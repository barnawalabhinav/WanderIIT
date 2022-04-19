#include "Player.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>

using namespace std;

#define PORT 8080

class server
{
public:
    server();
    ~server();

    int server_fd, new_socket, valread;
    char message[20];
    char buffer[1024] = {0};
    
    int setupConnection();
    int chartoint(char ch);
    char *sendData(Player *p);
    void recvData(Player *p);
    void extract_data(char data[], int &x, int &y, int &w, int &h, int &won, int &quit, int &miles);
};
