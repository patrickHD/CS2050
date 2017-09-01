BIN = l10
CC = gcc
CFLAGS = -Wall -g

$(BIN) : lab10.c BST.o
	$(CC) $(CFLAGS) lab10.c BST.o -o $(BIN)

BST.o : BST.c
	$(CC) $(CFLAGS) BST.c -c

clean:
	rm *.o $(BIN)
