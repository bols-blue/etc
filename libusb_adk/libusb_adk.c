/*
 * simplectrl.c
 * This file is part of OsciPrime
 *
 * Copyright (C) 2011 - Manuel Di Cerbo
 *
 * OsciPrime is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * OsciPrime is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OsciPrime; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "libusb_adk.h"

#define IN 0x85
#define OUT 0x07

#define VID 0x22b8
//#define VID 0x18D1
#define GOOGLE_VID 0x18D1
#define PID 0x70a8

#define ACCESSORY_PID 0x2D00
#define ACCESSORY_PID_ALT 0x2D01

#define LEN 2

/*
   If you are on Ubuntu you will require libusb as well as the headers...
   We installed the headers with "apt-get source libusb"
   gcc simplectrl.c -I/usr/include/ -o simplectrl -lusb-1.0 -I/usr/include/ -I/usr/include/libusb-1.0

   Tested for Nexus S with Gingerbread 2.3.4
 */
static void error(int code);
static void status(int code);
//static
static struct libusb_device_handle* handle;
static char stop;
static char success = 0;
int open_accesory_dev()
{
	libusb_device **devs;
	int r;
	ssize_t cnt;

	if( libusb_init(NULL) < 0)
		return -1;

	cnt = libusb_get_device_list(NULL, &devs);
	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return -1;
		}

		if(desc.idVendor == VID && desc.idProduct == PID){
			printf("%04x:%04x (bus %d, device %d)\n",
					desc.idVendor, desc.idProduct,
					libusb_get_bus_number(dev), libusb_get_device_address(dev));
			libusb_open(dev,&handle);
			return 0;
		}else if(desc.idVendor == GOOGLE_VID && desc.idProduct == PID){
			printf("%04x:%04x (bus %d, device %d)\n",
					desc.idVendor, desc.idProduct,
					libusb_get_bus_number(dev), libusb_get_device_address(dev));
			return libusb_open(dev,handle);
		}
	}
	return -1;
}
void print_devs(libusb_device **devs)
{
	libusb_device *dev;
	int i = 0;

	while ((dev = devs[i++]) != NULL) {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return;
		}

		printf("%04x:%04x (bus %d, device %d)\n",
			desc.idVendor, desc.idProduct,
			libusb_get_bus_number(dev), libusb_get_device_address(dev));
	}
}

int mainPhase(){
	unsigned char buffer[500000];
	int response = 0;
	static int transferred;
	
	sleep(5);
	response = libusb_bulk_transfer(handle,IN,buffer,16384, &transferred,0);
	if(response < 0){error(response);return -1;}

	response = libusb_bulk_transfer(handle,IN,buffer,500000, &transferred,0);
	if(response < 0){error(response);return -1;}

}


int init(){
	libusb_init(NULL);
	if((handle = libusb_open_device_with_vid_pid(NULL, VID, PID)) == NULL){
		fprintf(stdout, "Problem acquireing handle\n");
		return -1;
	}
	libusb_claim_interface(handle, 0);
	return 0;
}

int closeHandle(){
	//TODO free all transfers individually...
	//if(ctrlTransfer != NULL)
	//	libusb_free_transfer(ctrlTransfer);
	if(handle != NULL)
		libusb_release_interface (handle, 0);
	libusb_exit(NULL);
	return 0;
}

int chAccessoryMode(
		const char* manufacturer,
		const char* modelName,
		const char* description,
		const char* version,
		const char* url,
		const char* serialNumber){

	unsigned char ioBuffer[2];
	int devVersion;
	int response;
	int tries = 5;

	response = libusb_control_transfer(
			handle, //handle
			0xC0, //bmRequestType
			51, //bRequest
			0, //wValue
			0, //wIndex
			ioBuffer, //data
			2, //wLength
			0 //timeout
			);

	if(response < 0){error(response);return-1;}

	devVersion = ioBuffer[1] << 8 | ioBuffer[0];
	fprintf(stdout,"Verion Code Device: %d\n", devVersion);

	usleep(1000);//sometimes hangs on the next transfer :(

	response |= libusb_control_transfer(handle,0x40,52,0,0,manufacturer,strlen(manufacturer),0);
	response |= libusb_control_transfer(handle,0x40,52,0,1,modelName,strlen(modelName)+1,0);
	response |= libusb_control_transfer(handle,0x40,52,0,2,description,strlen(description)+1,0);
	response |= libusb_control_transfer(handle,0x40,52,0,3,version,strlen(version)+1,0);
	response |= libusb_control_transfer(handle,0x40,52,0,4,url,strlen(url)+1,0);
	response |= libusb_control_transfer(handle,0x40,52,0,5,serialNumber,strlen(serialNumber)+1,0);
	if(response < 0){error(response);return -1;}

	fprintf(stdout,"Accessory Identification sent\n", devVersion);

	response = libusb_control_transfer(handle,0x40,53,0,0,NULL,0,0);
	if(response < 0){error(response);return -1;}


	if(handle != NULL)
		libusb_release_interface (handle, 0);

	fprintf(stdout,"Attempted to put device into accessory mode\n", devVersion);

	for(;;){//attempt to connect to new PID, if that doesn't work try ACCESSORY_PID_ALT
		tries--;
		if((handle = libusb_open_device_with_vid_pid(NULL, GOOGLE_VID, ACCESSORY_PID)) == NULL){
			if(tries < 0){
				libusb_claim_interface(handle, 0);
				return -1;
			}
		}else{
			break;
		}
		sleep(1);
	}
	libusb_claim_interface(handle, 0);
	fprintf(stdout, "Interface claimed, ready to transfer data\n");
	return 0;
}

static void error(int code){
	fprintf(stdout,"\n");
	switch(code){
		case LIBUSB_ERROR_IO:
			fprintf(stdout,"Error: LIBUSB_ERROR_IO\nInput/output error.\n");
			break;
		case LIBUSB_ERROR_INVALID_PARAM:
			fprintf(stdout,"Error: LIBUSB_ERROR_INVALID_PARAM\nInvalid parameter.\n");
			break;
		case LIBUSB_ERROR_ACCESS:
			fprintf(stdout,"Error: LIBUSB_ERROR_ACCESS\nAccess denied (insufficient permissions).\n");
			break;
		case LIBUSB_ERROR_NO_DEVICE:
			fprintf(stdout,"Error: LIBUSB_ERROR_NO_DEVICE\nNo such device (it may have been disconnected).\n");
			break;
		case LIBUSB_ERROR_NOT_FOUND:
			fprintf(stdout,"Error: LIBUSB_ERROR_NOT_FOUND\nEntity not found.\n");
			break;
		case LIBUSB_ERROR_BUSY:
			fprintf(stdout,"Error: LIBUSB_ERROR_BUSY\nResource busy.\n");
			break;
		case LIBUSB_ERROR_TIMEOUT:
			fprintf(stdout,"Error: LIBUSB_ERROR_TIMEOUT\nOperation timed out.\n");
			break;
		case LIBUSB_ERROR_OVERFLOW:
			fprintf(stdout,"Error: LIBUSB_ERROR_OVERFLOW\nOverflow.\n");
			break;
		case LIBUSB_ERROR_PIPE:
			fprintf(stdout,"Error: LIBUSB_ERROR_PIPE\nPipe error.\n");
			break;
		case LIBUSB_ERROR_INTERRUPTED:
			fprintf(stdout,"Error:LIBUSB_ERROR_INTERRUPTED\nSystem call interrupted (perhaps due to signal).\n");
			break;
		case LIBUSB_ERROR_NO_MEM:
			fprintf(stdout,"Error: LIBUSB_ERROR_NO_MEM\nInsufficient memory.\n");
			break;
		case LIBUSB_ERROR_NOT_SUPPORTED:
			fprintf(stdout,"Error: LIBUSB_ERROR_NOT_SUPPORTED\nOperation not supported or unimplemented on this platform.\n");
			break;
		case LIBUSB_ERROR_OTHER:
			fprintf(stdout,"Error: LIBUSB_ERROR_OTHER\nOther error.\n");
			break;
		default:
			fprintf(stdout, "Error: unkown error\n");
	}
}

static void status(int code){
	fprintf(stdout,"\n");
	switch(code){
		case LIBUSB_TRANSFER_COMPLETED:
			fprintf(stdout,"Success: LIBUSB_TRANSFER_COMPLETED\nTransfer completed.\n");
			break;
		case LIBUSB_TRANSFER_ERROR:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_ERROR\nTransfer failed.\n");
			break;
		case LIBUSB_TRANSFER_TIMED_OUT:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_TIMED_OUT\nTransfer timed out.\n");
			break;
		case LIBUSB_TRANSFER_CANCELLED:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_CANCELLED\nTransfer was cancelled.\n");
			break;
		case LIBUSB_TRANSFER_STALL:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_STALL\nFor bulk/interrupt endpoints: halt condition detected (endpoint stalled).\nFor control endpoints: control request not supported.\n");
			break;
		case LIBUSB_TRANSFER_NO_DEVICE:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_NO_DEVICE\nDevice was disconnected.\n");
			break;
		case LIBUSB_TRANSFER_OVERFLOW:
			fprintf(stdout,"Error: LIBUSB_TRANSFER_OVERFLOW\nDevice sent more data than requested.\n");
			break;
		default:
			fprintf(stdout,"Error: unknown error\nTry again(?)\n");
			break;
	}
}
