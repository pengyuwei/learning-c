.DEFAULT_GOAL := all

CXX = g++
CFLAGS = -WALL -g -O0 -v

main : sdl.cpp
	$(CXX) sdl.cpp -o sdl.out

.PHONY : all
all : main

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*