#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "open_close.h"
#include "write_read.h"

int main()
{
    int file;
    
    file = open_to_write();

    write_to_file(file);

    close_file(file);

    file = open_to_read();

    read_from_file(file);

    close_file(file);

    file = open_to_read();

    reverse_print(file);

    close_file(file);

    return 0;
}
