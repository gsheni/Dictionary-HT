# Define the compiler
CC=g++
# Define the compiler options
CFLAGS=-O2
# Define the linker
LINK=g++
# Define the dependencies

all: Dictionary

# Define the dependencies
Dictionary: Dictionary.o
	$(LINK) -o Dictionary Dictionary.o  
Dictionary.o: Dictionary.cpp List.h Hashtable.h DictionaryEntry.h Dictionary.py
	$(CC) -c $(CFLAGS) Dictionary.cpp

clean:
	/bin/rm -f Dictionary Dictionary.o
