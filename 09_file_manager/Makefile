OBJMODULES = *.o 
CFLAGS = -g -Wall -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

phonebook: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@
run: file_manager
	./file_manager
clean:
	rm -f *.o file_manager
