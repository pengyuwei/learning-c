.DEFAULT_GOAL := all

CC = gcc
CXX = c++
CFLAGS = -Wall -g

base : sort.cpp bitcoin.c
	$(CXX) $(CFLAGS) -DNDEBUG -D_GNU_SOURCE sort.cpp -o sort.out
	$(CC) $(CFLAGS) bitcoin.c -o bitcoin.out
	
.PHONY : all
all : base

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -rf *.out.*
