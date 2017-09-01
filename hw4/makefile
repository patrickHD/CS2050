BIN = hw4
CC = gcc
CFLAGS = -Wall -g

$(BIN) : hw4.c link.o
	$(CC) $(CFLAGS) hw4.c link.o -o $(BIN)

link.o : link.c
	$(CC) $(CFLAGS) link.c -c

clean:
	rm *.o $(BIN)
