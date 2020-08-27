.DEFAULT_GOAL := all

CFLAGS=-std=c++11

thread :  thread.c
	c++ thread.c -o thread.out -lpthread

clang : clang.c
	c++ clang.c -o main.out

base : base.c
	$(CC) base.c -o base.out
	
.PHONY : all
all : thread clang base

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -f AUTHORS
	@rm -f COPYING
	@rm -f ChangeLog
	@rm -f INSTALL
	@rm -f NEWS
	@rm -f README
	@rm -f aclocal.m4
	@rm -f compile
	@rm -f config.h.in
	@rm -f config.log
	@rm -f config.status
	@rm -f configure
	@rm -f configure.scan
	@rm -f depcomp
	@rm -f install-sh
	@rm -f missing
	@rm -f autoscan.log
	@rm -rf autom4te.cache