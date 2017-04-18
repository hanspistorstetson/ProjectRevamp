all: dbtest

dbtest: dbtest.o event.o user.o sqlite3.o 
	g++ -o dbtest event.o dbtest.o user.o sqlite3.o -lpthread -ldl

event.o: event.cpp event.h sqlite3.h
	g++ -c event.cpp

dbtest.o: dbtest.cpp sqlite3.h event.h
	g++ -c dbtest.cpp

sqlite3.o: sqlite3.h sqlite3.c
	gcc -c sqlite3.c

user.o: user.cpp user.h sqlite3.h
	g++ -c user.cpp


.PHONY: clean
clean:
	rm -f *.o dbtest
