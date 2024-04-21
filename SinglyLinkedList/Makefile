CC = g++
CFLAGS = -std=c++11 -Wall

EXECUTABLE = myprogram

all: $(EXECUTABLE)

$(EXECUTABLE): node.o linkedlist.o main.o
	$(CC) $(CFLAGS) $^ -o $@

node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp -o node.o

linkedlist.o: linkedlist.cpp linkedlist.h node.h
	$(CC) $(CFLAGS) -c linkedlist.cpp -o linkedlist.o

main.o: main.cpp linkedlist.h node.h
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f *.o $(EXECUTABLE)

.PHONY: all clean
