.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

base : base.c
	$(CC) base.c -o base.out

.PHONY : all
all : base

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.so