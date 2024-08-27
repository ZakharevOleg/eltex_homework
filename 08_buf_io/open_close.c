#include <stdio.h>
#include <stdlib.h>

#include "open_close.h"

void open_to_write(FILE *file_to_save)
{
    file_to_save = fopen("file.txt", "w");
    if (!file_to_save) {
        perror("fopen");
        exit(1);
    }
}

/*
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
*/

void close_file(FILE *file_to_save)
{   
    fclose(file_to_save);
}
