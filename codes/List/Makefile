CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
INC = ../../inc
LIB = ../../lib

CBS_C = $(wildcard CursorBased/*.c)
CBS_PROGS = $(patsubst %.c,%,$(CBS_C))

LL_C = $(wildcard LinkedList/*.c)
LL_PROGS = $(patsubst %.c,%,$(LL_C))

ARRAY_C = $(wildcard Array/*.c)
ARRAY_PROGS = $(patsubst %.c,%,$(ARRAY_C))

.PHONY: print clean cursor linked array

cursor: $(CBS_PROGS)
linked: $(LL_PROGS)
array: $(ARRAY_PROGS)

%: %.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@

clean:
	del Array\*.exe CursorBased\*.exe LinkedList\*.exe *.exe Array\*.o

print: ; $(info $$ARRAY_O is [$(ARRAY_O)]) echo migz
