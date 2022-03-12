CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
INC = ../../libdsa/inc
LIB = ../../libdsa/lib

.PHONY: clean

%: %.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@	

clean:
	del Array\*.exe CursorBased\*.exe LinkedList\*.exe BitVector\*.exe
