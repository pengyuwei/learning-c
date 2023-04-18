.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

io:
	$(CC) $(CFLAGS) blocking_io.c -o blocking_io.out
	$(CC) $(CFLAGS) server-1.c -o server-1.out
	$(CC) $(CFLAGS) server-2.c -o server-2.out
	$(CC) $(CFLAGS) client-1.c -o client-1.out
	$(CC) $(CFLAGS) client-2.c -o client-2.out

.PHONY : all
all : io

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*