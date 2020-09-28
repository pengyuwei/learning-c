.DEFAULT_GOAL := all

CC = g++
CFLAGS = -Wall -g -std=c++11

main : 11.cpp
	$(CC) $(CFLAGS) 11.cpp -o 11.out

.PHONY : all
all : main 

clean:
	@rm -f *.out
	@rm -rf *.out.*