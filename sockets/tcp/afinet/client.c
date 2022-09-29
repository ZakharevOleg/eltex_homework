#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

	int client_socket, connection_status;
    struct sockaddr_in server_address;
    char client_message[256] = "Hi server!";
    char server_message[256];

	client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }
	
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1){
	    perror("ERROR connecting");
        exit(1);
	}
	
    send(client_socket, client_message, sizeof(client_message), 0);
	recv(client_socket, &server_message, sizeof(server_message), 0);
	printf("The server sent the message: %s\n", server_message);

	close(client_socket);

	return 0;
}
