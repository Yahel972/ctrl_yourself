#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include "Message.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include "MouseClickMessage.h"
#include "MousePosMessage.h"
#include "KeyboardMessage.h"
#include <regex>

#define BUFFER_SIZE 256

class Server
{
public:
	Server();
	~Server();
	void serve(int port);

	Message* setMessageType(std::string msg);

private:

	void acceptClient();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};
