.DEFAULT_GOAL := all


CC = gcc
CXX = g++
CFLAGS = -Wall -g

so: so_call.cpp so.c
	$(CC) $(CFLAGS) -fPIC -c so.c -o libso.o
	$(CC) -shared libso.o -o libso.so
	$(CXX) so_call.cpp -L. -lso -o so.out

.PHONY : all
all : so

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.so