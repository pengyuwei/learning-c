.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

kqueue: kqueue.c
	$(CC) $(CFLAGS) kqueue.c -o kqueue.out

.PHONY : all
all : kqueue

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*