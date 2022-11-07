#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main()
{
    
    }

    int pid;
    pid = fork();
    if (pid == -1) {

    }
    if (pid == 0) {
    }

    wait(NULL);

    printf("Ok\n");
    return 0;
}
