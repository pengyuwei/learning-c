.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

scope: scope.c
	$(CC) $(CFLAGS) scope.c -o scope.out

.PHONY : all
all : scope

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*