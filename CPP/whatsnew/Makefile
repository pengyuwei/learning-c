.DEFAULT_GOAL := all

CC = clang
CFLAGS11 = -Wall -g -std=c++11
CFLAGS17 = -Wall -g -std=c++17

main : 11.cpp
	$(CC) $(CFLAGS11) 11.cpp -o 11.out
	$(CC) $(CFLAGS17) 17.cpp -o 17.out

.PHONY : all
all : main 

clean:
	@rm -f *.out
	@rm -rf *.out.*