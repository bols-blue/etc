
namespace socket_client{
void l_error(const char *msg);
}
namespace socket_server{
extern void l_error(const char *msg);

class socket_server{
	public :
		socket_server(int portno);
		~socket_server();
		int write(char buff[],int size);
		int write(char buff[]);
		int read(char buff[],int size);
		int read(char buff[]);
		FILE * getFileDescriptor();
		void viewLog();
	protected:
		int sockfd, newsockfd;
		FILE * sock_file;
		struct sockaddr_in serv_addr, cli_addr;
		socklen_t clilen;
		void close_error(int);
};
}
