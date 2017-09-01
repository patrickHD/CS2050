BIN = BST
CC = gcc
CFLAGS = -Wall -g

$(BIN) : runner.c BST.o
	$(CC) $(CFLAGS) runner.c BST.o -o $(BIN)

BST.o : BST.c
	$(CC) $(CFLAGS) BST.c -c

clean:
	rm *.o $(BIN)
