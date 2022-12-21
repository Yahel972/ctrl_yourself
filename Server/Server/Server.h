#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
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

	void connectToServer(std::string serverIP, int port);
	void startConversation();

	Message* setMessageType(std::string msg);

private:
	void receiveData(SOCKET clientSocket);

	SOCKET _serverSocket;
};
