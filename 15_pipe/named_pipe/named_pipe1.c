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
    int fd;
    char *myfifo = "myfifo";
    char mess1[10];
    char mess[] = "Hello";

    mkfifo(myfifo, 0666);
    if ((fd = open(myfifo, O_WRONLY)) == -1){
        handle_error("open");
    }
    write(fd, mess, sizeof(mess));
    close(fd);

    if ((fd = open(myfifo, O_RDONLY)) == -1){
        handle_error("open");
    }
    read(fd, mess1, sizeof(mess1));
    printf("Received message from User2: %s\n", mess1);
    close(fd);

    printf("Ok\n");
    return 0;
}
