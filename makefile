CC=g++
CFLAGS=-std=c++11 -Wall -ggdb

main: ArrayList.h.gch main.cpp
	$(CC) $(CFLAGS) main.cpp -o main
ArrayList.h.gch: ArrayList.h
	$(CC) $(CFLAGS) ArrayList.h
clean: 
	rm -f ArrayList.h.gch main
