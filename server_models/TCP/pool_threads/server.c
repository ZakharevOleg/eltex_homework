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
#define MAX_CONNECTING 5

int client_socket[MAX_CONNECTING] = {0};
int server_socket;

void *new_client(void *args)
{
    int i = *(int *)args;
    struct sockaddr_in client_addres;
    socklen_t client_len;
    client_len = sizeof(client_addres);
    char server_message[BUF_SIZE] = "Hi client!";
    char client_message[BUF_SIZE];
    
    client_socket[i] = accept(server_socket, (struct sockaddr*)&client_addres, &client_len);
        if (client_socket[i] < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

    send(client_socket[i], server_message, BUF_SIZE, 0);
    while (1) {
        recv(client_socket[i], client_message, BUF_SIZE, 0);
        printf("The client message: %s\n", client_message);
    }

}

int main(void)
{
    int  bind_status, i;
    int client_count[MAX_CONNECTING] = {0};
    struct sockaddr_in server_addres;
    pthread_t tid[MAX_CONNECTING];

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
    
    for ( i = 0; i < MAX_CONNECTING; i++) {
        client_count[i] = i;
        if (pthread_create(&tid[i], NULL, new_client, &client_count[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }
    
    while (i != 1) {
        printf("Please enter 1 to exit:\n");
        scanf("%d", &i);
        getchar();
    }

    close(server_socket);

    return 0;
}
