OBJMODULES = menu.o contacts.o open_close.o
CFLAGS = -g -Wall -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

phonebook: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@
run: phonebook
	./phonebook
clean:
	rm -f *.o phonebook
