.DEFAULT_GOAL := all

thread :  thread.c
	c++ thread.c -o thread -lpthread

clang : clang.c
	c++ clang.c -o main

.PHONY : all
all : thread clang

clean:
	rm -f *.o
	rm -f main
	rm -f thread
	rm -f a.out
