#---------- TO DO: 1. Using make doesn't compile files, gives some error. 2. Using make run1 compiles files but doesn't run them automatically ------------

# Compiler Settings
CC=g++
CFLAGS=-c -Wall

# Source Files
SRCS=run1.cpp run2.cpp run3.cpp run4.cpp

# Object Files
OBJS=$(SRCS:.cpp=.o)

# Targets
all: run1 run2 run3 run4

run1: run1.o
	$(CC) $(CFLAGS) -o run1 run1.o
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

# Object files
run1.o: run1.cpp
	$(CC) $(CFLAGS) -c run1.cpp

run2.o: run2.cpp
	$(CC) $(CFLAGS) -c run2.cpp

run3.o: run3.cpp
	$(CC) $(CFLAGS) -c run3.cpp

run4.o: run4.cpp
	$(CC) $(CFLAGS) -c run4.cpp

# Object file rules
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f *.o run1 run2