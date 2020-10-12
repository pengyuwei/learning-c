.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g -O0

epoll: epoll.c
	$(CC) $(CFLAGS) epoll.c -o epoll.out

curses: curses.c
	$(CC) $(CFLAGS) curses.c -lncurses -I/usr/include/ncurses -o curses.out

other: readline.c
	$(CC) readline.c -lreadline -o readline.out

.PHONY : all
all : epoll curses other

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*