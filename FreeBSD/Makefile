.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

kevent: kevent.c
	$(CC) $(CFLAGS) kevent.c -o kevent.out

.PHONY : all
all : kevent

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*