.DEFAULT_GOAL := base

CXX = c++
CFLAGS = -Wall -g -std=c++11

base : 3.cpp
	$(CXX) $(CFLAGS) 3.cpp -o 3.out

buildall : 1.cpp 3.cpp
	$(CXX) $(CFLAGS) 1.cpp -o 1.out
	$(CXX) $(CFLAGS) 2.cpp -o 2.out
	$(CXX) $(CFLAGS) 3.cpp -o 3.out

.PHONY : base
all : buildall

run:
	./3.out

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -rf *.out.*
