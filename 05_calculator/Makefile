OBJMODULES = operations.o interface.o
CFLAGS = -g -Wall -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
calculator: main.c $(OBJMODULES) 
	$(CC) $(CFLAGS) $^ -o  $@
run: calculator
	./calculator
clean:
	rm -f *.o calculator
