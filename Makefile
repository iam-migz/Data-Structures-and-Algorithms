# -*- MakeFile -*-

# target: dependencies
#	action

all: libdsa

libdsa: obj/arrayhelper.o obj/cb_helper.o obj/ll_helper.o
	ar -rc lib/libdsa.a $^

obj/arrayhelper.o: src/arrayhelper.c inc/arrayhelper.h
	gcc -c src/arrayhelper.c -o $@

obj/cb_helper.o: src/cb_helper.c inc/cb_helper.h
	gcc -c src/cb_helper.c -o $@

obj/ll_helper.o: src/ll_helper.c inc/ll_helper.h
	gcc -c src/ll_helper.c -o $@

sandbox: sandbox.c	
	gcc sandbox.c -ldsa -I inc -L lib -o sandbox