#include "Player.h"
#include "Hurdles.h"
#include "WanderIIT.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>

using namespace std;

#define PORT 8080

class client
{
public :
	int client_fd, new_socket, valread;
	char buffer[1024] = { 0 };
	char message[20];
    
    int setupConnection();
    char* sendData(Player *p);
    void recvData(Player *p);
    void extract_data(char data[], int x, int y, int w, int h, int won, int quit, int miles);
};
