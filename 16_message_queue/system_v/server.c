#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE     128

typedef struct msgbuf
{
    long    mtype;
    char    mtext[MAXSIZE];
}msgbuf;

int main()
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    struct msgbuf sendmessage;
    struct msgbuf rcvmessage;
    size_t buflen;

    if ((key = ftok("./server", 123)) < 0){
        perror("ftok");
        exit(1);
    }

    if ((msqid = msgget(key, msgflg )) < 0){
        perror("msgget");
        exit(1);
    }

    sendmessage.mtype = 1;
    strcpy(sendmessage.mtext, "Hello from server");
    buflen = strlen(sendmessage.mtext) + 1 ;
    
    if (msgsnd(msqid, &sendmessage, buflen, IPC_NOWAIT) < 0){
        printf ("Error while seding a message");
        perror("msgsnd");
        exit(1);
    } else {
        printf("Message sent: %s\n", sendmessage.mtext);
    }
   
       if (msgrcv(msqid, &rcvmessage, MAXSIZE, 2, 0) < 0){
        perror("msgrcv");
        exit(1);    
    } else {
        printf("Message receive: %s\n", rcvmessage.mtext);
    }


    exit(EXIT_SUCCESS);
}
