.DEFAULT_GOAL := all

CC = g++
CFLAGS = -WALL

main : main.cpp func.cpp
	$(CC) func.cpp main.cpp -o main.out

.PHONY : all
all : main

clean:
	@rm -f *.out