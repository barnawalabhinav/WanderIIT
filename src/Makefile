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

client.o: client.cpp client.h
	$(CC) $(CF) -c client.cpp $(LINKER_FLAGS)

server.o: server.cpp server.h
	$(CC) $(CF) -c server.cpp $(LINKER_FLAGS)

buttons.o: buttons.cpp buttons.h
	$(CC) $(CF) -c buttons.cpp $(LINKER_FLAGS)

instructions.o: instructions.cpp instructions.h
	$(CC) $(CF) -c instructions.cpp $(LINKER_FLAGS)

Player.o: Player.cpp GameMap.h
	$(CC) $(CF) -c Player.cpp $(LINKER_FLAGS)

WanderIIT.o: WanderIIT.cpp WanderIIT.h
	$(CC) $(CF) -c WanderIIT.cpp $(LINKER_FLAGS)
	
Hurdles.o: Hurdles.cpp Hurdles.h
	$(CC) $(CF) -c Hurdles.cpp $(LINKER_FLAGS)

main.o: main.cpp
	$(CC) $(CF) -c main.cpp $(LINKER_FLAGS)

#To run the game as server
server:
	./game.out

#To run the game as client
client:
	./game.out 1

clean:
	rm *.o
