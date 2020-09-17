.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

epoll: epoll.c
	$(CC) $(CFLAGS) epoll.c -o epoll.out

.PHONY : all
all : epoll

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*