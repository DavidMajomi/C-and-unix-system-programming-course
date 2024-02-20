# Calculator

# MACROS (variables)
CC=gcc
LIBS=-lm
OUTPUT=calc

all: calc

calc: main.o get.o parse.o execute.o
	$(CC) main.o get.o parse.o execute.o -o $(OUTPUT) $(LIBS)
	@echo ""
	@echo "Same as: gcc main.c get.c parse.c execute.c -o calc -lm"
	@echo ""

main.o: main.c
	$(CC) -c main.c

get.o: get.h get.c
	$(CC) -c get.c

parse.o: parse.h parse.c
	$(CC) -c parse.c

execute.o: execute.h execute.c
	$(CC) -c execute.c

clean:
	rm -f *.o $(OUTPUT)

# GNU makefile extension: clean doesn't depend on any files
.PHONY: clean
