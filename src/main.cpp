#include <sys/epoll.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd==-1) {
        return -1;
    }

    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_port = htons(9000);
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(fd,(struct sockaddr *)&my_addr, sizeof(my_addr))==-1) {
        return -1;
    }
    
    if (listen(fd, 1024) == -1) {
        return -1; 
    }

    for(;;) {
        usleep(100);
    }
}
