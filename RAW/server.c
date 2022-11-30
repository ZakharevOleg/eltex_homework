#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <errno.h>

#define BUF_SIZE 256

int main(){
    int server_socket;
    struct sockaddr_in server_address, client_address;
    char server_message[BUF_SIZE] = "Message from you: ";
    char client_message[BUF_SIZE];
    socklen_t client_struct_length = sizeof(client_address);
    
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1){
        perror("socket");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        perror("bind");
        exit(1);
    }
    
    if (recvfrom(server_socket, client_message, sizeof(client_message), 0,
        (struct sockaddr*)&client_address, &client_struct_length) == -1){
        perror("recvfrom");
        exit(1);
    }
    
    printf("Msg from client: %s\n", client_message);
    strncat(server_message, client_message, 20);
    
    if (sendto(server_socket, server_message, strlen(server_message), 0,
        (struct sockaddr*)&client_address, client_struct_length) == -1){
        perror("sendto");
        exit(1);
    }
    printf("Msg to client: %s\n", server_message);
    
    close(server_socket);
    
    return 0;
}
