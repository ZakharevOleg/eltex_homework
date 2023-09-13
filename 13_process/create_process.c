#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
    {
        fork();
        printf ("This process ID of this process is %d\n", getpid());
        printf ("This parent process ID of this process is %d\n", getppid());
        return 0;
    }
