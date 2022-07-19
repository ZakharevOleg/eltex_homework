#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int file, sz, i;
    const char *buf = "Random text";
    ssize_t writing, reading;
    int len = 64;
    char buffer[len + 1];
    char ch;
    off_t ret;
    struct stat st;

    file = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if(file == -1) {
        perror("open");
        exit (1);
    }

    writing = write (file, buf, strlen(buf));
    if (writing == -1) {
        perror("write");
        exit (1);
    }
    close(file);

    file = open("file.txt", O_RDONLY);
    if(file == -1) {
        perror("open");
        exit (1);
    }

    while ((reading = read (file, buffer, len)) != 0) {
        if (reading == -1) {
            perror ("read");
            exit (1);
        }
        buffer[reading] = 0;
        printf("%s\n", buffer);
    }
    close(file);

    file = open("file.txt", O_RDONLY);
    if(file == -1) {
        perror("open");
        exit (1);
    }
    stat("file.txt", &st);
    sz = st.st_size;

    for (i = 1; i <= sz; i++)
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
        if (sz == i) {
            printf ("\n");
        }

    }
    return 0;
}
