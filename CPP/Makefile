.DEFAULT_GOAL := all

CC = g++
CFLAGS = -WALL

main : main.cpp func.cpp
	$(CC) func.cpp main.cpp -o main.out

stl : stl.cpp
	$(CC) stl.cpp -o stl.out

.PHONY : all
all : main stl

clean:
	@rm -f *.out