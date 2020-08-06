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
	rm -f AUTHORS
	rm -f COPYING
	rm -f ChangeLog
	rm -f INSTALL
	rm -f NEWS
	rm -f README
	rm -f aclocal.m4
	rm -f compile
	rm -f config.h.in
	rm -f config.log
	rm -f config.status
	rm -f configure
	rm -f configure.scan
	rm -f depcomp
	rm -f install-sh
	rm -f missing
	rm -rf autom4te.cache
	rm -f autoscan.log