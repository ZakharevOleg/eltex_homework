#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    char getstring[100];
    char *cmdline[10];
    char *ls_line[10];
    char *grep_line[10];
    int i = 0;
    char *token;
    pid_t pid;

    printf("Please enter command and arguments:\n");
    fgets(getstring, 99, stdin);
    getstring[strlen(getstring)-1] = 0;
    token = strtok(getstring, "|");
    while(token != NULL) {
        cmdline[i] = token;
        token = strtok (NULL, "|");
        i++;
    }

    i = 0;
    token = strtok(cmdline[0], " ");
    while(token != NULL){
        ls_line[i] = token;
        token = strtok (NULL, " ");
        i++;
    }

    i = 0;
    token = strtok(cmdline[1], " ");
    while(token != NULL) {
        grep_line[i] = token;
        token = strtok (NULL, " ");
        i++;
    }
    
    pipe(fd);
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        execvp(ls_line[0], ls_line);
        perror(ls_line[0]);
        exit(1);
    }
    pid = fork();
    if (pid == 0) {
        close(fd[1]);
        dup2(fd[0], 0);
        execvp(grep_line[0], ls_line);
        perror(grep_line[0]);
        exit(1);
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}
