BIN = myObj
CC = gcc
CFLAGS = -Wall -g

$(BIN) : potato.c queue.o
	$(CC) $(CFLAGS) potato.c queue.o -o $(BIN)
	
fact.o : queue.c queue.h
	$(CC) $(CFLAGS) queue.c -c

clean:
	rm *.o $(BIN)