all: main

main: main.o sqlite3.o
	g++ -o main main.o sqlite3.o -lpthread -ldl

main.o: main.cpp sqlite3.h
	g++ -c  main.cpp

#Using gcc for the C code!
sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

.PHONY: clean
clean:
	rm -f *.o main
