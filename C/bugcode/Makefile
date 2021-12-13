.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g -O0

base : longsize.c
	@$(CC) $(CFLAGS) longsize.c -o longsize.out
	
.PHONY : all
all : base

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -rf *.out.*