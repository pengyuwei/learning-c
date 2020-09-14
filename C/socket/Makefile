.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

socket: server.c client.c
	$(CC) $(CFLAGS) server.c -o server.out
	$(CC) $(CFLAGS) client.c -o client.out

shm: shm_c.c shm_s.c
	$(CC) $(CFLAGS) shm_c.c -o shm_c.out
	$(CC) $(CFLAGS) shm_s.c -o shm_s.out

.PHONY : all
all : socket shm

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*