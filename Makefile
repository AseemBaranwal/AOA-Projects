#---------- TO DO: 1. Using make doesn't compile files, gives some error. 2. Using make run1 compiles files but doesn't run them automatically ------------

# Compiler Settings
CC=g++
CFLAGS=-std=c++11

# Targets
default: clean

all: run1 run2 run3 run4

run1: run1.cpp
	$(CC) $(CFLAGS) -o run1 run1.cpp
	./run1

run2: run2.cpp
	$(CC) $(CFLAGS) -o run2 run2.cpp
	./run2

run3: run3.cpp
	$(CC) $(CFLAGS) -o run3 run3.cpp
	./run3

run4: run4.cpp
	$(CC) $(CFLAGS) -o run4 run4.cpp
	./run4

run5: run5.cpp
	$(CC) $(CFLAGS) -o run5 run5.cpp
	./run5

# Clean up
.PHONY:clean
clean:
	rm -rf run1 run2 run3 run4 run5