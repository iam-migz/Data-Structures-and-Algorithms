CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic
INC = ../../libdsa/inc
LIB = ../../libdsa/lib

.PHONY: clean

%: %.c
	$(CC) $(CFLAGS) $< -ldsa -I $(INC) -L $(LIB) -o $@
	./$@	

clean:
	del CloseHashing\*.exe OpenHashing\*.exe Practice\*.exe *.exe