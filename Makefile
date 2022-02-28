# -*- MakeFile -*-

# target: dependencies
#	action

all: libdsa

libdsa: obj/array.o obj/cursorbased.o obj/linkedlist.o obj/stack.o obj/queue.o
	ar -rc lib/libdsa.a $^

obj/array.o: src/array.c inc/array.h
	gcc -c $< -o $@

obj/cursorbased.o: src/cursorbased.c inc/cursorbased.h
	gcc -c $< -o $@

obj/linkedlist.o: src/linkedlist.c inc/linkedlist.h
	gcc -c $< -o $@

obj/stack.o: src/stack.c inc/stack.h
	gcc -c $< -o $@

obj/queue.o: src/queue.c inc/queue.h
	gcc -c $< -o $@



sandbox: sandbox.c	
	gcc sandbox.c -ldsa -I inc -L lib -o sandbox

checklib:
	ar t lib/libdsa.a

clean:
	del lib\*.a obj\*.o