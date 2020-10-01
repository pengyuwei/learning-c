.DEFAULT_GOAL := all

CC = gcc
CXX = g++
CFLAGS = -WALL -g -O0

overload : class.cpp overload.cpp
	$(CXX) class.cpp overload.cpp -o overload.out
	$(CC) class.cpp overload.cpp -o overloadc.out

main : class.cpp
	$(CXX) class.cpp -D_CLASSMAIN_ -o class.out

.PHONY : all
all : main overload

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*