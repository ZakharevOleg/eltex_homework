#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <sys/un.h>

int main(){
    int client_socket, connection_status;
    struct sockaddr_un server_address;
    char client_message[256] = "Hi server!";
    char server_message[256];

    client_socket = socket(AF_LOCAL, SOCK_DGRAM, 0);

    if(client_socket == -1){
        perror("ERROR opening socket");
        exit(1);
    }

    server_address.sun_family = AF_LOCAL;
    strcpy(server_address.sun_path, "/tmp/mysock.sock");
    
    connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1){
	    perror("ERROR connecting");
        exit(1);
	}

    
    send(client_socket, client_message, sizeof(client_message), 0);
	recv(client_socket, &server_message, sizeof(server_message), 0);
	printf("The server sent the message: %s\n", server_message);

	close(client_socket);
    unlink("/tmp/mysock.sock");

    return 0;
}
