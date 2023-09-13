#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>

#define BUF_SIZE 256
#define MAX_CONNECTING 10

void *new_client(void *args)
{
    int client_socket = *((int *)args);
    char server_message[BUF_SIZE] = "Hi client!";
    char client_message[BUF_SIZE];

    send(client_socket, server_message, BUF_SIZE, 0);
    while (1) {
        recv(client_socket, client_message, BUF_SIZE, 0);
        printf("The client message: %s\n", client_message);
    }

}

int main(void)
{
    int server_socket, client_socket, bind_status, client_count;
    struct sockaddr_in server_addres, client_addres;
    pthread_t tid[MAX_CONNECTING];
    socklen_t client_len;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    memset(&server_addres, 0, sizeof(server_addres));
    server_addres.sin_family = AF_INET;
    server_addres.sin_port = htons(9001);
    server_addres.sin_addr.s_addr = htonl(INADDR_ANY);

    bind_status = bind(server_socket, (struct sockaddr*) &server_addres, sizeof(server_addres));
    if (bind_status < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    if (listen(server_socket, MAX_CONNECTING) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    } else {
        printf("Server listening...\n");
    }
    client_count = 0;
    client_len = sizeof(client_addres);
    
    while (1) {
        
        client_socket = accept(server_socket, (struct sockaddr*)&client_addres, &client_len);
        if (client_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        client_count++;
        if (client_count > MAX_CONNECTING) {
            printf("Max client count");
            exit(EXIT_FAILURE); 
        }

        if (pthread_create(&tid[client_count], NULL, new_client, &client_socket) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
