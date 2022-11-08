#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define handle_error(str) do{\
    perror(str);\
    return 1;}while(0)

int main()
{
    int fd1;
    char *myfifo = "myfifo";
    char mes1[10];
    char mes[] = "Hi";

    mkfifo(myfifo, 0666);

    if ((fd1 = open(myfifo, O_RDONLY)) == -1){
        handle_error("open");
    }
    read(fd1, mes1, sizeof(mes1));
    printf("Received message from User1: %s\n", mes1);
    close(fd1);

    if ((fd1 = open(myfifo, O_WRONLY)) == -1){
        handle_error("open");
    }
    write(fd1, mes, sizeof(mes));
    close(fd1);

    printf("Ok\n");
    return 0;
}
