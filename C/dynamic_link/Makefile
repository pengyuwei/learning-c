.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

so: so_call.c so.c
	$(CC) $(CFLAGS) -fPIC -c so.c -o libso.o
	$(CC) -shared libso.o -o libso.so
	$(CC) -o so.out so_call.c -L. -lso

.PHONY : all
all : so

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.so