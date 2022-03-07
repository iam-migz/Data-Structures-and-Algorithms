CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
INC = ../../inc
LIB = ../../lib

.PHONY: print clean

Array/%: Array/%.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@

CursorBased/%: CursorBased/%.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@

LinkedList/%: LinkedList/%.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@

clean:
	del Array\*.exe CursorBased\*.exe LinkedList\*.exe *.exe

print: ; $(info $$ARRAY_O is [$(ARRAY_O)]) echo migz
