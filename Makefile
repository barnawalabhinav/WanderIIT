#CC specifies which compiler we're using
CC = g++

#Display all warnings
CF = -Wall -g

#Paths to be included
#IPATH = -I./glad/include/

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
#COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -ldl -lSDL2_mixer -lSDL2_net

#SRC_DIR specifies the directly of the source files. All .cpp files in this directory will be compiled
SRC_DIR := .

########################################################
#To Compile all files of the same project in a directory
#Uncomment the declarations till the nearest 'all' label
########################################################

#OBJ_DIR specifies the directory of the object files. All the oblect files go to this directory
#OBJ_DIR := .

#SRC_FILES specifies which files to compile as part of the project
#SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

#OBJ_NAME specifies the name of our exectuable
#OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

#This is the target that compiles our executable
#all: $(OBJ_FILES)
#	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@ $^

#This is the target that compiles individual files
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
#	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -c -o $@ $<

#======================================================#

all: main.o WanderIIT.o Hurdles.o network.o Player.o
	$(CC) $(CF) -o game.out main.o WanderIIT.o Hurdles.o Player.o network.o $(LINKER_FLAGS)
	
#glad.o: ./glad/src/glad.c
#	$(CC) $(CF) $(IPATH) -c ./glad/src/glad.c -o glad.o $(LINKER_FLAGS)

network.o: network.cpp
	$(CC) $(CF) -c network.cpp $(LINKER_FLAGS)

Player.o: Player.cpp
	$(CC) $(CF) -c Player.cpp $(LINKER_FLAGS)

WanderIIT.o: WanderIIT.cpp
	$(CC) $(CF) -c WanderIIT.cpp $(LINKER_FLAGS)
	
Hurdles.o: Hurdles.cpp
	$(CC) $(CF) -c Hurdles.cpp $(LINKER_FLAGS)

main.o: main.cpp
	$(CC) $(CF) -c main.cpp $(LINKER_FLAGS)
	 
clean:
	rm *.o

#To build the server
server: 
	g++ Socket/server.cpp -o Socket/server.o $(LINKER_FLAGS)

#To initialize the server
init:
	./Socket/server.o

#To run the game
test:
	./game.out
