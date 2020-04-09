CC=gcc
CFLAGS=-Wall

all : board.o conway.o
	$(CC) -o conway.out $(CFLAGS) board.o conway.o

board.o : board.c board.h
	$(CC) -c board.c

conway.o : conway.c sum.h
	$(CC) -c conway.c

clean :
	rm *.out
