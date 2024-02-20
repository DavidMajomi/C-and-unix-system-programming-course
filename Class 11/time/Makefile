# Time

# MACROS (variables)
CC=gcc
LIBS=
OUTPUT=time
SOURCES=main.c time.h time.c

all: time

time: $(SOURCES)
	$(CC) $(LIBS) $(SOURCES) -o $(OUTPUT)
clean:
	rm -f $(OUTPUT)

# GNU makefile extension: clean doesn't depend on any files
.PHONY: clean
