CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system -lboost_thread

all: ClientMain
	g++ -o bin/BBclient bin/ConnectionHandler.o bin/ClientMain.o bin/Task.o $(LDFLAGS)

ClientMain: bin/ClientMain.o bin/ConnectionHandler.o bin/Task.o

bin/ClientMain.o: src/ClientMain.cpp
	g++ $(CFLAGS) -o bin/ClientMain.o src/ClientMain.cpp

bin/ConnectionHandler.o: src/ConnectionHandler.cpp
	g++ $(CFLAGS) -o bin/ConnectionHandler.o src/ConnectionHandler.cpp

bin/Task.o: src/Task.cpp
	g++ $(CFLAGS) -o bin/Task.o src/Task.cpp

.PHONY: clean
clean:
	rm -f bin/*