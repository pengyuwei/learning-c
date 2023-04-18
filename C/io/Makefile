.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

ipc:
	$(CC) $(CFLAGS) blocking_io.c -o blocking_io.out
	$(CC) $(CFLAGS) server-1.c -o server-1.out
	$(CC) $(CFLAGS) client.c -o client.out

.PHONY : all
all : ipc

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*