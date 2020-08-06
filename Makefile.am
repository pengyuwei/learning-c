bin_PROGRAMS = main thread
main_SOURCES = clang.c
main_LDADD = $(LIBOBJS)

main.o: clang.c
    $(COMPILE) clang.c -o main

thread.o: thread.c
    $(COMPILE) thread.c -o thread -lpthread

# info_TEXINFOS = main.texi
