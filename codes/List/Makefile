CC=gcc
CFLAGS=-Wall -Wextra -pedantic
INC = ../../inc
LIB = ../../lib

CB = CursorBased/
LL = LinkedList/
.PHONY: print run_cb_problems clean

print: ; $(info $$exp is [${exp}]) echo migz


list_example: list_example.c
	$(CC) $(CFLAGS) list_example.c -ldsa -I $(INC) -L $(LIB) -o list_example

# Cursorbased files
cb_problems: $(CB)problems.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $(CB)problems

cb_operations: $(CB)operations.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $(CB)operations

run_cb_problems: cb_problems
	./$(CB)problems

run_cb_operations: cb_operations
	./$(CB)operations

clean:
	del Array\*.exe CursorBased\*.exe LinkedList\*.exe