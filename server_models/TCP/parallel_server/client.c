#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 256

int main(void)
{
    int client_socket, connection_status;
    struct sockaddr_in server_addres;
    char server_message[BUF_SIZE];
    char client_message[BUF_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addres, 0, sizeof(server_addres));
    server_addres.sin_family = AF_INET;
    server_addres.sin_port = htons(9001);
    server_addres.sin_addr.s_addr = htonl(INADDR_ANY);

    connection_status = connect(client_socket, (struct sockaddr *) &server_addres, sizeof(server_addres));
	if (connection_status == -1) {
	    perror("connect");
        exit(EXIT_FAILURE);
	}
	
	recv(client_socket, &server_message, sizeof(server_message), 0);
	printf("The server sent the message: %s\n", server_message);
    while (1) {
        printf("Please enter message for server:\n");
        fgets(client_message, BUF_SIZE, stdin);
        client_message[strlen(client_message)-1] = 0;
        send(client_socket, client_message, sizeof(client_message), 0);
    }

    return 0;
}
