#include "client.h"

#define PORT 8080

client::client()
{}

client::~client()
{}

int client::chartoint(char ch)
{
	int x = ch - '0';
	return x;
}

int client::setupConnection(const char *IPaddr)
{
	struct sockaddr_in serv_addr;
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, IPaddr, &serv_addr.sin_addr) <= 0)
	{
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(client_fd, (struct sockaddr *)&serv_addr,
				sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	return 0;
}

void client::extract_data(char data[], int &x, int &y, int &w, int &h, int &won, int &quit, int &miles)
{
	x = 1000 * chartoint(data[0]) + 100 * chartoint(data[1]) + 10 * chartoint(data[2]) + chartoint(data[3]);
	y = 1000 * chartoint(data[5]) + 100 * chartoint(data[6]) + 10 * chartoint(data[7]) + chartoint(data[8]);
	w = chartoint(data[10]);
	h = chartoint(data[12]);
	won = chartoint(data[14]);
	quit = chartoint(data[16]);
	miles = chartoint(data[18]);
}

char *client::sendData(Player *p)
{
	string string_of_x;
	string string_of_y;
	if (p->position.x < 10)
	{
		string_of_x = ("0" + ("0" + ("0" + to_string(p->position.x))));
	}
	else if (p->position.x < 100)
	{
		string_of_x = ("0" + ("0" + to_string(p->position.x)));
	}
	else if (p->position.x < 1000)
	{
		string_of_x = ("0" + to_string(p->position.x));
	}
	else if (p->position.x < 10000)
	{
		string_of_x = to_string(p->position.x);
	}

	if (p->position.y < 10)
	{
		string_of_y = ("0" + ("0" + ("0" + to_string(p->position.y))));
	}
	else if (p->position.y < 100)
	{
		string_of_y = ("0" + ("0" + to_string(p->position.y)));
	}
	else if (p->position.y < 1000)
	{
		string_of_y = "0" + to_string(p->position.y);
	}
	else if (p->position.y < 10000)
	{
		string_of_y = to_string(p->position.y);
	}

	string sending_data = string_of_x + "_" + string_of_y + "_" + to_string(p->position.w) + "_" + to_string(p->position.h) + "_" + to_string(p->GameWon) + "_" + to_string(p->quit) + "_" + to_string(p->health);
	strcpy(message, sending_data.c_str());
	int size = send(client_fd, &message, strlen(message), 0);

	if (size < 0)
	{
		printf("error size < 0");
	}
	return message;
}

void client::recvData(Player *p)
{
	valread = read(client_fd, buffer, 1024);
	extract_data(buffer, p->position.x, p->position.y, p->position.w, p->position.h, p->GameWon, p->quit, p->health);
}