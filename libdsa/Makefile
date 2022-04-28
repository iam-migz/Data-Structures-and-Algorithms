# -*- MakeFile -*-

# target: dependencies
#	action
CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
.PHONY: all clean checklib libtest libdsa

all: libdsa

libdsa: obj/array.o obj/cursorbased.o obj/linkedlist.o obj/stack.o obj/queue.o obj/BST.o
	ar -rc lib/libdsa.a $^

obj/%.o: src/%.c inc/%.h
	$(CC) $(CFLAGS) -c $< -o $@

libtest: libtest.c
	$(CC) $(CFLAGS) $< -ldsa -I inc -L lib -o $@
	./$@

checklib:
	ar t lib/libdsa.a

clean:
	del *.exe lib\*.a obj\*.o