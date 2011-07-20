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
namespace socket_server{

void l_error(const char *msg)
{
	std::fprintf(stderr,"%s\n",msg);
	exit(1);
}

const char *error_string[4] ={
	"fd が有効なオープンされたディスクリプターでない。",
	"close() コールがシグナルにより中断 (interrupt) された。",
	"I/O エラーが発生した。",
	""};

void socket_server::close_error(int error)
{
	if(error <0){
	char buff[30];
	switch(errno){
		case EBADF:
			fprintf(stderr,"errorno=%i,%s \n",errno,error_string[0]);
			break;
		case EINTR:
			fprintf(stderr,"errorno=%i,%s \n",errno,error_string[1]);
			break;
		case EIO:
			fprintf(stderr,"errorno=%i,%s \n",errno,error_string[2]);
			break;
		default:
			fprintf(stderr,"errorno=%i \n",error);
			exit(1);
			break;
	}
	}
}

socket_server::socket_server(int portno)
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) 
		l_error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr,
				sizeof(serv_addr)) < 0) 
		l_error("ERROR on binding");
	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, 
			(struct sockaddr *) &cli_addr, 
			&clilen);
	if (newsockfd < 0) 
		l_error("ERROR on accept");
	sock_file = fdopen(newsockfd,"w+");
}

socket_server::~socket_server()
{
	int ret ;
	std::fflush(sock_file);
	ret = std::fclose(sock_file);
	close_error(ret);
	ret = close(newsockfd);
	close_error(ret);
	ret = close(sockfd);
	close_error(ret);
}

int
socket_server::read(char buff[],int size)
{
	char *read_char = std::fgets(buff,size,sock_file);
	return sizeof(read_char);
}

int
socket_server::read(char buff[])
{
	return this->read(buff,sizeof(buff));
}

int
socket_server::write(char buff[],int size){
	return std::fputs(buff,sock_file);
}

int
socket_server::write(char buff[]){
	return this->write(buff,sizeof(buff));
}
FILE* socket_server::getFileDescriptor()
{
	return sock_file;
}
}

