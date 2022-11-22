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
    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if ((qd_client = mq_open ("/mq", O_RDONLY)) == -1) {
        perror ("mq_open");
        exit(1);
    }
    
    if (mq_receive (qd_client, rcvmessage, MSG_BUFFER_SIZE, NULL) == -1) {
        perror ("mq_receive");
        exit (1);
    } else {
        printf("Message receive: %s\n", rcvmessage);
    }

    exit(EXIT_SUCCESS);
}

