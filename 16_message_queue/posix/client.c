#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main (int argc, char **argv)
{
    mqd_t qd_client;
    char rcvmessage[MSG_BUFFER_SIZE];
    char sendmessage[MSG_BUFFER_SIZE] = "Hello from client";


    if ((qd_client = mq_open ("/sp-example-server", O_RDWR)) == -1) {
        perror ("mq_open");
        exit(1);
    }
    
    if (mq_receive (qd_client, rcvmessage, MSG_BUFFER_SIZE, NULL) == -1) {
        perror ("mq_receive");
        exit (1);
    } else {
        printf("Message receive: %s\n", rcvmessage);
    }
    
    if ((mq_send(qd_client, sendmessage, strlen (sendmessage) + 1, 0)) == -1) {
        perror("mq_send");
        exit(1);
    } else {
        printf("Message sent: %s\n", sendmessage);
    }

    exit(EXIT_SUCCESS);
}

