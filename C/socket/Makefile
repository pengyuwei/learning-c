.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

socket: server.c client.c
	$(CC) $(CFLAGS) server.c -o server.out
	$(CC) $(CFLAGS) client.c -o client.out

.PHONY : all
all : socket

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*