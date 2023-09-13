CC = gcc
OBJMODULES = operations.o
CFLAGS = -g -Wall -ansi -pedantic

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@
calculator: calculator.c $(OBJMODULES) 
	$(CC) $(CFLAGS) $^ -o  $@
run: calculator
	./calculator
clean:
	rm -f *.o calculator
