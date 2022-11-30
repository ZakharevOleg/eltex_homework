#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main ()
{
    mqd_t qd_server;
    struct mq_attr attr;
    char sendmessage[MSG_BUFFER_SIZE] = "Hello from server";
    char rcvmessage[MSG_BUFFER_SIZE];

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    if ((qd_server = mq_open ("/sp-example-server", O_CREAT | O_RDWR, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("mq_open");
        exit(1);
    }
    

    if ((mq_send(qd_server, sendmessage, strlen (sendmessage) + 1, 0)) == -1) {
        perror("mq_send");
        exit(1);
    } else {
        printf("Message sent: %s\n", sendmessage);
    }
    
    if (mq_receive (qd_server, rcvmessage, MSG_BUFFER_SIZE, NULL) == -1) {
        perror ("mq_receive");
        exit (1);
    } else {
        printf("Message receive: %s\n", rcvmessage);
    }
    
    mq_close(qd_server);
    mq_unlink("/sp-example-server");
    
    exit(EXIT_SUCCESS);
}
