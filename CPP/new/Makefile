.DEFAULT_GOAL := all

CC = g++
CFLAGS = -Wall -g -std=c++11

main : features.cpp
	$(CC) $(CFLAGS) features.cpp -o features.out

.PHONY : all
all : main 

clean:
	@rm -f *.out
	@rm -rf *.out.*