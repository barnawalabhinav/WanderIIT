#CC specifies which compiler we're using
CC = g++

#Display all warnings
CF = -Wall -g

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -ldl -lSDL2_mixer

#SRC_DIR specifies the directly of the source files. All .cpp files in this directory will be compiled
SRC_DIR := .

all: main.o WanderIIT.o Hurdles.o Player.o buttons.o instructions.o client.o server.o
	$(CC) $(CF) -o game.out main.o WanderIIT.o Hurdles.o Player.o buttons.o instructions.o client.o server.o $(LINKER_FLAGS)

client.o: src/client.cpp src/client.h
	$(CC) $(CF) -c src/client.cpp $(LINKER_FLAGS)

server.o: src/server.cpp src/server.h
	$(CC) $(CF) -c src/server.cpp $(LINKER_FLAGS)

buttons.o: src/buttons.cpp src/buttons.h
	$(CC) $(CF) -c src/buttons.cpp $(LINKER_FLAGS)

instructions.o: src/instructions.cpp src/instructions.h
	$(CC) $(CF) -c src/instructions.cpp $(LINKER_FLAGS)

Player.o: src/Player.cpp src/GameMap.h
	$(CC) $(CF) -c src/Player.cpp $(LINKER_FLAGS)

WanderIIT.o: src/WanderIIT.cpp src/WanderIIT.h
	$(CC) $(CF) -c src/WanderIIT.cpp $(LINKER_FLAGS)
	
Hurdles.o: src/Hurdles.cpp src/Hurdles.h
	$(CC) $(CF) -c src/Hurdles.cpp $(LINKER_FLAGS)

main.o: src/main.cpp
	$(CC) $(CF) -c src/main.cpp $(LINKER_FLAGS)

#To run the game as server
server:
	./game.out

#To run the game as client
client:
	./game.out 1

clean:
	rm *.o
