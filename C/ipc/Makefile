.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -Wall -g

ipc: shm_c.c shm_s.c
	$(CC) $(CFLAGS) shm_c.c -o shm_c.out
	$(CC) $(CFLAGS) shm_s.c -o shm_s.out
	$(CC) $(CFLAGS) pipe.c -o pipe.out

.PHONY : all
all : ipc

upload:
	scp * ff@build-server:~/build/

clean:
	@rm -f *.out
	@rm -f *.o
	@rm -f *.a
	@rm -rf *.out.*