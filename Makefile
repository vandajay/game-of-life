CC=gcc
CFLAGS=-Wall

all : board.o conway.o
	$(CC) -o a.out $(CFLAGS) board.o conway.o 

conway.o : conway.c board.h
	$(CC) $(CFLAGS) -c conway.c

board.o : board.c board.h
	$(CC) $(CFLAGS) -c board.c

clean :
	rm *.out *.o tmp.txt

run :
	./run.sh 20 20 100
