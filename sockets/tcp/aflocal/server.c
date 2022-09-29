#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

int main() {
    
    int server_socket, recive_socket, bind_status;
    struct sockaddr_un server_address;
    char server_message[256] = "Hi client!";
    char client_message[256];

    server_socket = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (server_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sun_family = AF_LOCAL;
    strcpy(server_address.sun_path, "/tmp/mysock.sock");

    bind_status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    if (bind_status == -1){
        perror("ERROR connecting");
        exit(1);
    }
    
    if (listen(server_socket, 5) == -1){
        perror("ERROR listening");
        exit(1);
    }

    recive_socket = accept(server_socket, NULL, NULL);
    if (recive_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }


    send(recive_socket, server_message, sizeof(server_message), 0);
    recv(recive_socket, &client_message, sizeof(client_message), 0);
    printf("The client sent the message: %s\n", client_message);
    
    close(recive_socket);
    close(server_socket);
    unlink("/tmp/mysock.sock");

	return 0;
}
