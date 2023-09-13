#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    
    int server_socket, recive_socket, bind_status;
    struct sockaddr_in server_address, client_addres;
    char server_message[256] = "Hi client!";
    char client_message[256];
    socklen_t client_len;
    client_len = sizeof(client_addres);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind_status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_status == -1){
        perror("ERROR connecting");
        exit(1);
    }

    if (listen(server_socket, 5) == -1){
        perror("ERROR listening");
        exit(1);
    }


    recive_socket = accept(server_socket, (struct sockaddr*)&client_addres, &client_len);
    if (recive_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }


    send(recive_socket, server_message, sizeof(server_message), 0);
    recv(recive_socket, &client_message, sizeof(client_message), 0);
    printf("The client sent the message: %s\n", client_message);
    
    close(recive_socket);
    close(server_socket);

	return 0;
}
