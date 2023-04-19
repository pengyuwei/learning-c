.DEFAULT_GOAL := all

CC = gcc
CXX = g++
CFLAGS = -Wall -g -O2

overload : class.cpp overload.cpp
	$(CXX) class.cpp overload.cpp -o overload.out
	$(CC) class.cpp overload.cpp -o overloadc.out

main : class.cpp
	$(CXX) class.cpp -D_CLASSMAIN_ -o class.out
	$(CXX) $(CFLAGS) explicit.cpp -o explicit.out

.PHONY : all
all : main overload

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*