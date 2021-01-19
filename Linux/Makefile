.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g -O0

linux: epoll.c 2038.c
	$(CC) $(CFLAGS) epoll.c -o epoll.out
	$(CC) -m32 2038.c -o 2038.out

curses: curses.c
	$(CC) $(CFLAGS) curses.c -lncurses -I/usr/include/ncurses -o curses.out

readline: readline.c
	$(CC) readline.c -lreadline -o readline.out

other: fileio.c
	$(CC) $(CFLAGS) fileio.c -o fileio.out

.PHONY : all
all : linux curses readline other

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*