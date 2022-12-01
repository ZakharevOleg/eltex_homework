#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <errno.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/udp.h>

#define BUF_SIZE 256
#define IP_HEADER_LEN 20

int main(){
    int client_socket;
    struct sockaddr_in server_address;
    struct udphdr* udp_header;
    struct iphdr* ip_header;
    char packet[BUF_SIZE];
    char *message;
    int val = 1;

    client_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if(client_socket == -1){
        perror("socket");
        exit(1);
    }

    if (setsockopt(client_socket, IPPROTO_IP, IP_HDRINCL, &val, sizeof(val)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8888);
    server_address.sin_addr.s_addr = INADDR_ANY;

    ip_header = (struct iphdr*) packet;

    ip_header->ihl = 5;
    ip_header->version = 4;
    ip_header->tos = 0;
    ip_header->tot_len = htons(BUF_SIZE);
    ip_header->id = 0;
    ip_header->frag_off = 0;
    ip_header->ttl = 255;
    ip_header->protocol = IPPROTO_UDP;
    ip_header->check = 0;
    ip_header->saddr = INADDR_ANY;
    ip_header->daddr = INADDR_ANY;
    
    udp_header = (struct udphdr*)(packet + sizeof(struct iphdr));

    udp_header->uh_sport = htons(7777);
    udp_header->uh_dport = htons(8888);
    udp_header->uh_ulen = htons(BUF_SIZE - sizeof(struct iphdr));
    udp_header->uh_sum = 0;

    message = packet + sizeof (struct iphdr) + sizeof(struct udphdr); // start message
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
            printf("The message from server: %s\n", message);
            break;
        }
    }
    
    close(client_socket);
    return 0;
}
