# -*- MakeFile -*-

# target: dependencies
#	action
CC=gcc
CFLAGS=-Wall -Wextra -pedantic
.PHONY: all clean checklib codes

all: libdsa

libdsa: obj/array.o obj/cursorbased.o obj/linkedlist.o obj/stack.o obj/queue.o
	ar -rc lib/libdsa.a $^

obj/array.o: src/array.c inc/array.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/cursorbased.o: src/cursorbased.c inc/cursorbased.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/linkedlist.o: src/linkedlist.c inc/linkedlist.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/stack.o: src/stack.c inc/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/queue.o: src/queue.c inc/queue.h
	$(CC) $(CFLAGS) -c $< -o $@


libtest: libtest.c
	$(CC) $(CFLAGS) libtest.c -ldsa -I inc -L lib -o libtest

checklib:
	ar t lib/libdsa.a

clean:
	del *.exe lib\*.a obj\*.o