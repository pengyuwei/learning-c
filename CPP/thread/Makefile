.DEFAULT_GOAL := all

CC = g++
CFLAGS = -Wall -g -std=c++11

main : base.cpp
	$(CC) base.cpp -lpthread -o base.out
	$(CC) $(CFLAGS) pc11.cpp -lpthread -o pc11.out

.PHONY : all
all : main 

clean:
	@rm -f *.out
	@rm -rf *.out.*