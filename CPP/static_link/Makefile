.DEFAULT_GOAL := all

CXX = g++
CC = gcc
CFLAGS = -Wall -g

liba: lib_call.cpp lib.c
	$(CC) $(CFLAGS) -fPIC -c lib.c -o libfunc.o
	ar crv libfunc.a libfunc.o
	# $(CC) -static liblib.o -o liblib.a
	$(CXX) lib_call.cpp -L. -lfunc -o lib.out

.PHONY : all
all : liba

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a