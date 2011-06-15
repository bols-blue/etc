
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <cstdlib>
#include <cstring> // includes bzero
#include <iterator>
#include <iostream>
#include <cerrno>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "server.h"

void l_error(const char *msg)
{
	std::fprintf(stderr,"%s\n",msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	char buffer[256];
	socket_server::socket_server *server;
	int n;
	if (argc < 2) {
		std::fprintf(stderr,"ERROR, no port provided\n");
		exit(1);
	}
	int data = atoi(argv[1]);
	server = new socket_server::socket_server(data);
	bzero(buffer,256);
	n = server->read(buffer,255);
	if (n < 0) l_error("ERROR reading from socket");
	if (n == 0) l_error("ERROR reading zero byte");
	printf("Here is the message: %s\n",buffer);
	n = server->write("I got your message");
	if (n < 0) l_error("ERROR writing to socket");
	if (n == 0) l_error("ERROR writing zero byte");
	delete server;
	return 0; 
}
