#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "write_read.h"



int write_to_file(int file)
{
    const char *buf = "Random text";
    ssize_t writing;
    writing = write (file, buf, strlen(buf));
    if (writing == -1) {
        perror("write");
        exit (1);
    }
    return 0;
}

int read_from_file(int file)
{
    int len = 64;
    char buffer[65];
    ssize_t reading;

    while ((reading = read (file, buffer, len)) != 0) {
        if (reading == -1) {
            perror ("read");
            exit (1);
        }
        buffer[reading] = 0;
        printf("%s\n", buffer);
    }
    return 0;
}

int reverse_print(int file)
{
    int size, i;
    ssize_t reading;
    char ch;
    off_t ret;
    struct stat st;

    stat("file.txt", &st);
    size = st.st_size;

    for (i = 1; i <= size; i++)
    {
        ret = lseek (file, i * (-1), SEEK_END);
        if (ret == (off_t) -1) {
            perror ("lseek");
            exit (1);
        }
        reading = read (file, &ch, 1);
        if (reading == -1) {
            perror ("read");
            exit (1);
        }
        printf ("%c", ch);
        if (size == i) {
            printf ("\n");
        }

    }
    return 0;
}
