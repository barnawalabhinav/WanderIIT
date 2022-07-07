#include "server.h"

server::server()
{}

server::~server()
{}

int server::chartoint(char ch){
    int x = ch - '0';
    return x;
}

int server::setupConnection()
{
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0))
		== 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				SO_REUSEADDR | SO_REUSEPORT, &opt,
				sizeof(opt))) {
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	if (bind(server_fd, (struct sockaddr*)&address,
			sizeof(address))
		< 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0) {
		perror("listen");
		exit(EXIT_FAILURE);
	}
	if ((new_socket
		= accept(server_fd, (struct sockaddr*)&address,
				(socklen_t*)&addrlen))
		< 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}

	return 0;
}

void server::extract_data(char data[], int &x, int &y, int &w, int &h, int &won, int &quit, int &miles)
{
	x = 1000*chartoint(data[0])+ 100*chartoint(data[1])+10*chartoint(data[2])+chartoint(data[3]);
	y = 1000*chartoint(data[5])+ 100*chartoint(data[6])+10*chartoint(data[7])+chartoint(data[8]);
	w = chartoint(data[10]);
	h = chartoint(data[12]);
	won = chartoint(data[14]);
	quit = chartoint(data[16]);
	miles = chartoint(data[18]);
}

char* server::sendData(Player *p)
{
	string string_of_x; 
	string string_of_y;
	if(p->position.x<10){
		string_of_x = ("0" + ("0" + ("0" + to_string(p->position.x))));
	}
	else if(p->position.x<100){
		 string_of_x = ("0" + ("0" + to_string(p->position.x)));
	}
	else if(p->position.x<1000){
		 string_of_x = ("0" + to_string(p->position.x));
	}
	else if(p->position.x<10000){
		 string_of_x = to_string(p->position.x);
	}

	if(p->position.y<10){
		 string_of_y = ("0" + ("0" + ("0" + to_string(p->position.y))));
	}
	else if(p->position.y<100){
		 string_of_y = ("0" + ("0" + to_string(p->position.y)));
	}
	else if(p->position.y<1000){
		 string_of_y = "0" + to_string(p->position.y);
	}
	else if(p->position.y<10000){
		string_of_y = to_string(p->position.y);
	}

	string sending_data = string_of_x + "_" + string_of_y + "_" + to_string(p->position.w) + "_" + to_string(p->position.h) + "_" + to_string(p->GameWon) +  "_" + to_string(p->quit) +  "_" + to_string(p->health);
	strcpy(message, sending_data.c_str());
	int size = send(new_socket, &message, strlen(message), 0);

	if(size<0){
		printf("error size < 0");
	}
	return message;
}

void server::recvData(Player *p)
{
	valread = read(new_socket, buffer, 1024);
	extract_data(buffer, p->position.x, p->position.y, p->position.w, p->position.h, p->GameWon, p->quit, p->health);
}
