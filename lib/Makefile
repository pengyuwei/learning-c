.DEFAULT_GOAL := all

CXX = g++
CFLAGS = -Wall -g -O0 -v
SDLI = -I/usr/local/include/SDL2 -D_THREAD_SAFE
SDLL = -L/usr/local/lib -lSDL2

main : sdl.cpp
	$(CXX) $(CFLAGS) $(SDLI) $(SDLL) sdl.cpp -o sdl.out

.PHONY : all
all : main

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*