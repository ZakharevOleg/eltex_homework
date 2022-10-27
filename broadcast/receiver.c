#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <errno.h>

#define handle_error(str) do{\
    perror(str);\
    return 1;}while(0)

int main(void){
    int recv_socket;
    struct sockaddr_in recv_address;
    char recv_message[256];
    socklen_t len = sizeof(struct sockaddr_in);

    recv_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(recv_socket == -1){
        handle_error("socket");
    }
    
    
    recv_address.sin_family = AF_INET;
    recv_address.sin_port = htons(8888);
    inet_aton("255.255.255.255", &(recv_address.sin_addr));

    if(bind(recv_socket, (struct sockaddr*)&recv_address, len) == -1){
        close(recv_socket);
        handle_error("bind");
    }

    if(recvfrom(recv_socket, recv_message, 255, 0, NULL, 0 ) == -1){
        close(recv_socket);
        handle_error("recvfrom");
    }
    printf("Received: %s\n", recv_message);

    close(recv_socket);
    return 0;
}
