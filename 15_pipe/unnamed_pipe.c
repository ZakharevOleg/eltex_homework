#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

#define handle_error(str) do{\
    perror(str);\
    return 1;}while(0)

int main()
{
    int fd1[2];
    int fd2[2];
    int pid;

    if (pipe(fd1) == -1){
        handle_error("pipe");
    }

    if (pipe(fd2) == -1){
        handle_error("pipe");
    }

    pid = fork();
    if (pid == -1){
        handle_error("fork");
    }
    else if (pid > 0){
        char mess1[10];
        char mess[] = "Hello";

        close(fd1[0]);
        write(fd1[1], mess, strlen(mess) + 1);
        close(fd1[1]);

        wait(NULL);

        close(fd2[1]);
        read(fd2[0], mess1, 10);
        printf("Received message from child: %s\n", mess1);
        close(fd2[0]);

        printf("Ok\n");
        return 0;
    }
    else{
        char mes1[10];
        char mes[] ="Hi";

        close(fd1[1]);
        read(fd1[0], mes1, 10);
        printf("Received message from parent: %s\n", mes1);
        close(fd1[0]);
        
        close(fd2[0]);
        write(fd2[1], mes, strlen(mes) + 1);
        close(fd2[1]);

        exit(0);
    }
}
