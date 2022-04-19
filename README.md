# TASK 2: A 2-Player Maze Game

## Objective: Develop a two player maze game based on IIT Delhi Map

### Overview: The Game named 'WANDER IIT' has been completely developed in C++ using the SDL2 library for linux systems. It uses only the SDL2_mixer library (for music) besides the standard SDL2 library.

To install SDL2 library on linux, run

    sudo apt-get libsdl2-dev

To install SDL2_mixer library on linux, run

    sudo apt-get install libsdl2-mixer-dev

### Code Description:

This project contains the following:

   1. buttons.cpp       :- Creates a surface to choose the hostel, i.e., the starting point of the player
   2. client.cpp        :- Connects to the Server using its IP address and then transfers data as a client
   3. server.cpp        :- Accepts connection from the Client and transfers data as a server
   4. Hurdles.cpp       :- Declares the Hurdles that are the Profs and the Dogs and defines their movement on the map
   5. instructions.cpp  :- Creates a surface and displays the instructions
   6. Player.cpp        :- Declares a player and the associated variables such as its health, etc. and defines its movement
   7. WanderIIT.cpp     :- Instantiates Various functions and objects and controls the overall logic flow in the game
   8. main.cpp          :- Instantiates the game as server or client based on command line input
   9. GameMap.h         :- Contains the map of the game as an array of pixel values

### How to RUN:

To build and execute move to directory of the files and type, in the command line :
    
First run make on both the systems

    make

Next run make server on the system which is the server

    make server

Next run make client on the system which is the client

    make client

Next it asks the ip address of the server, enter the ip address of the server

    <ip address of the server>

TO obtain ip address in linux, go to terminal and type ifconfig

    ifconfig

If ifconfig is not found, run

    sudo apt-get install net-tools


Then to run the game, both the players need to follow the instructions given:
Clicking next on the instructions page
Followed by choosing their hostels

### Acknowledgments

    https://www.geeksforgeeks.org/
    https://lazyfoo.net/tutorials/SDL/index.php
    https://pixabay.com
    https://www.piskelapp.com/
    https://www.youtube.com/playlist?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx
    
