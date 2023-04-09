.DEFAULT_GOAL := all

CC = g++
CFLAGS = -WALL

stl : stl.cpp
	$(CC) stl.cpp -o stl.out
	$(CC) std.cpp -o std.out
	$(CC) string.cpp -o string.out
	$(CC) vector.cpp -o vector.out
	$(CC) map.cpp -o map.out
	$(CC) set.cpp -o set.out

.PHONY : all
all : stl

clean:
	@rm -f *.out
