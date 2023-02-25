#---------- TO DO: 1. Using make doesn't compile files, gives some error. 2. Using make run1 compiles files but doesn't run them automatically ------------

# Compiler Settings
CC=g++
CFLAGS=-c -Wall

# Targets
all: run1 run2 run3 run4

run1: run1.cpp
	$(CC) $(CFLAGS) -o run1 run1.cpp
	./run1

run2: run2.o
	$(CC) $(CFLAGS) -o run2 run2.o
	./run2

run3: run3.o
	$(CC) $(CFLAGS) -o run3 run3.o
	./run3

run4: run4.o
	$(CC) $(CFLAGS) -o run4 run4.o
	./run4

# Clean up
.PHONY:clean
clean:
	rm -f run1 run2