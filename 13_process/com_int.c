#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    char getstring[51];
    char delim[5] = " ";
    char *cmdline[10];
    int i = 0;
    char*token;
    printf("Please enter command and arguments:\n");
    fgets(getstring, 50, stdin);
    getstring[strlen(getstring)-1] = 0;

    token = strtok(getstring, delim);
    while(token != NULL) {
        cmdline[i] = token;
        token = strtok (NULL, delim);
        i++;
    }


    int pid;
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        execvp(cmdline[0], cmdline);
        perror(cmdline[0]);
        exit(1);
    }

    wait(NULL);

    printf("Ok\n");
    return 0;
}
