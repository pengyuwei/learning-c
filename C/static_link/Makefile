.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

liba: lib_call.c lib.c
	$(CC) $(CFLAGS) -fPIC -c lib.c -o libfunc.o
	ar crv libfunc.a libfunc.o
	# $(CC) -static liblib.o -o liblib.a
	$(CC) -o lib.out lib_call.c -L. -lfunc

.PHONY : all
all : liba

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a