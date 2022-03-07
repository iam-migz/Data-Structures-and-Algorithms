CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
INC = ../../inc
LIB = ../../lib

.PHONY: clean

%: %.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@	

clean:
	del Array\*.exe CursorBased\*.exe LinkedList\*.exe *.exe
