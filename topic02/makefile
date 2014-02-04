CC=g++
CFLAGS=-c -Wall -Wno-reorder
LDFLAGS=
SOURCES=CExample.cpp CGame.cpp CStateLogo.cpp CStateManagement.cpp CStatePoster.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=game

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)

run:
	./${EXECUTABLE}