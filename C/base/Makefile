.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

define:
	@$(CC) $(CFLAGS) -Wno-unused-variable def.c -o def.out

base : base.c heap.c stack.c mem.c
	$(CC) $(CFLAGS) base.c -o base.out
	$(CC) $(CFLAGS) heap.c -o heap.out
	$(CC) $(CFLAGS) stack.c -o stack.out
	$(CC) $(CFLAGS) mem.c -o mem.out
	$(CC) $(CFLAGS) rnd.c -o rnd.out
	$(CC) $(CFLAGS) input.c -o input.out
	
.PHONY : all
all : base

clean:
	@rm -f *.o
	@rm -f *.out
	@rm -rf *.out.*
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