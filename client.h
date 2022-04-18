#include "Player.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

#define PORT 8080

class client
{
public :
    client();
    ~client();

	int client_fd = 0, valread;
	char buffer[1024] = { 0 };
	char message[20];
    
    int setupConnection(const char *IPaddr);
    char* sendData(Player *p);
    void recvData(Player *p);
    int chartoint(char ch);
    void extract_data(char data[], int &x, int &y, int &w, int &h, int &won, int &quit, int &miles);
};
