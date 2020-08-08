.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -WALL

base : base.c
	$(CC) base.c -o base.out

.PHONY : all
all : base

clean:
	@rm -f *.out