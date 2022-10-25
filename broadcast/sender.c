#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <errno.h>

#define handler_error(str) do{\
    perror(str);\
    return 1;}while(0)

int main(void){
    int send_socket;
    struct sockaddr_in sender_address;
    char send_message[256] = "Hi reciever";
    socklen_t len = sizeof(struct sockaddr_in);
    int flag = 1;

    send_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(send_socket == -1){
        handler_error("socket");
    }
    
    if(setsockopt(send_socket, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(flag)) == -1){
        close(send_socket);
        handler_error("setsockopt");
    }
    
    sender_address.sin_family = AF_INET;
    sender_address.sin_port = htons(8888);
    inet_aton("255.255.255.255", &(sender_address.sin_addr));

    if(sendto(send_socket, send_message, strlen(send_message), 0,
        (struct sockaddr*)&sender_address, len) == -1){
        close(send_socket);
        handler_error("sendto");
    }
    
    close(send_socket);
    return 0;
}
