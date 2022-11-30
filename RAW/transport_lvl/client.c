#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <errno.h>
#include <netinet/in.h>
#include <netinet/udp.h>

#define BUF_SIZE 256
#define IP_HEADER_LEN 20

int main(){
    int client_socket;
    struct sockaddr_in server_address;
    struct udphdr* udp_packet;
    char packet[BUF_SIZE];
    char *message;

    client_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if(client_socket == -1){
        perror("socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    udp_packet = (struct udphdr*) packet;

    udp_packet->uh_sport = htons(7777);
    udp_packet->uh_dport = htons(8888);
    udp_packet->uh_ulen = htons(BUF_SIZE);
    udp_packet->uh_sum = 0;

    message = packet + sizeof(struct udphdr); // start message
    strcpy(message, "Hi server");

    if(sendto(client_socket, packet, sizeof(packet), 0,
        (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        perror("sendto");
        exit(1);
    }

    printf("The message to server: %s\n", message);

    while(1){
         if (recvfrom(client_socket, packet, sizeof(packet), 0, NULL, NULL) == -1) {
            perror("recvfrom");
            exit(1);
        }
        if ( ((struct udphdr*)(packet+IP_HEADER_LEN))->uh_sport == htons(8888)) {
            printf("The message from server: %s\n", message + IP_HEADER_LEN);
            break;
        }
    }
    
    close(client_socket);
    return 0;
}
