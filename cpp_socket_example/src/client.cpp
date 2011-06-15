#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

namespace socket_client{
void l_error(const char *msg)
{
    perror(msg);
    exit(0);
}
}
