CC = gcc
OBJMODULES = open_close.o write_read.o
CFLAGS = -g -Wall -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
readff: main.c $(OBJMODULES) 
	$(CC) $(CFLAGS) $^ -o  $@
run: readff
	./readff
clean:
	rm -f *.o *.txt readff 
