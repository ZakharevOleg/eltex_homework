#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>

int main(){
    int server_socket;
    struct sockaddr_in server_address, client_address;
    char server_message[256] = "Hi client!";
    char client_message[256];
    socklen_t client_struct_length = sizeof(client_address);
    
    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (server_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        perror("ERROR connecting");
        exit(1);
    }
    
    
    if (recvfrom(server_socket, client_message, sizeof(client_message), 0,
         (struct sockaddr*)&client_address, &client_struct_length) == -1){
        perror("ERROR receiving");
        exit(1);
    }
    
    printf("Msg from client: %s\n", client_message);
    
    if (sendto(server_socket, server_message, strlen(server_message), 0,
         (struct sockaddr*)&client_address, client_struct_length) == -1){
        perror("ERROR sending");
        exit(1);
    }
    
    // Close the socket:
    close(server_socket);
    
    return 0;
}
