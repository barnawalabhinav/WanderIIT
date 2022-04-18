// Server side C/C++ program to demonstrate Socket
// programming
#include "server.h"

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

void server::extract_data(char data[], int x, int y, int w, int h, int won, int quit, int miles)
{
	int j = 0, k = 0;
	char *temp_char;
	string temp_str = "";
	for (int i = 0; i < sizeof(data); i++)
	{
		if(data[i] = '_')
		{
			temp_str = temp_char;
			stringstream temp(temp_str);
			switch (j)
			{
			case 0:
				temp >> x;
				break;
			case 1:
				temp >> y;
				break;
			case 2:
				temp >> w;
				break;
			case 3:
				temp >> h;
				break;
			case 4:
				temp >> won;
				break;
			case 5:
				temp >> quit;
				break;
			case 6:
				temp >> miles;
				break;
			default:
				break;
			}
			j++;
			k = i;
		}
		else{
			temp_char[i-k] = data[i];
		}
	}
}

void server::sendData(Player *p)
{
	string str = to_string(p->position.x) + "_" + to_string(p->position.y) + "_" + to_string(p->position.w) + "_" + to_string(p->position.h) + "_" + to_string(p->GameWon) + "_" + to_string(p->quit) + "_" + to_string(p->CompletedMilestones);
	strcpy(message, str.c_str());
	int size = send(new_socket, message, strlen(message), 0);

	if(size < 0)
	{
		printf("Could not send data to the client");
	}
}

void server::recvData(Player *p)
{
	valread = read(new_socket, buffer, 1024);
}