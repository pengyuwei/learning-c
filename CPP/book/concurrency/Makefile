.DEFAULT_GOAL := all

CXX = g++
CFLAGS = -Wall -g -std=c++11

main : 
	$(CXX) $(CFLAGS) listing_1.1.cpp -lpthread -o 1.1.out
	$(CXX) $(CFLAGS) listing_2.1.cpp -lpthread -o 2.1.out
	$(CXX) $(CFLAGS) listing_2.1.1.cpp -lpthread -o 2.1.1.out
	$(CXX) $(CFLAGS) listing_2.2.cpp -lpthread -o 2.2.out
	$(CXX) $(CFLAGS) listing_2.3.cpp -lpthread -o 2.3.out

.PHONY : all
all : main 

clean:
	@rm -f *.out
	@rm -rf *.out.*