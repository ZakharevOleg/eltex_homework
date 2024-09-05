#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "open_close.h"

int open_to_write()
{
    int file;
    file = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file == -1) {
        perror("open");
        exit(1);
    }
    return file;
}

int open_to_read()
{
    int file;
    file = open("file.txt", O_RDONLY);
    if (file == -1) {
        perror("open");
        exit (1);
    }
    return file;
}

int close_file(int fd)
{    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
    return 0;
}
