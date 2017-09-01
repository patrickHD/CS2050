BIN = lab11
CC = gcc
CFLAGS = -Wall -g

$(BIN) : frontend.c parser.o
	$(CC) $(CFLAGS) frontend.c parser.o -o $(BIN)

parser.o : parser.c
	$(CC) $(CFLAGS) parser.c -c

clean:
	rm *.o $(BIN)
