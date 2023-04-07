.DEFAULT_GOAL := all

CXX = c++
CFLAGS = -Wall -g -std=c++11

base : 1.cpp
	$(CXX) $(CFLAGS) 1.cpp -o 1.out
	
.PHONY : all
all : base

run:
	./1.out

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -rf *.out.*
