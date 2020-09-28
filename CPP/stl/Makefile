.DEFAULT_GOAL := all

CC = g++
CFLAGS = -WALL

stl : stl.cpp
	$(CC) stl.cpp -o stl.out

.PHONY : all
all : stl

clean:
	@rm -f *.out