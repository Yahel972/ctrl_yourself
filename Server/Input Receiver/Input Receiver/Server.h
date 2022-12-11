#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include "Message.h"

#define BUFFER_SIZE 256

class Server
{
public:
	Server();
	~Server();
	void serve(int port);

private:

	void acceptClient();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};
