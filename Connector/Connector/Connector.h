#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <thread>

#define MAX_SIZE 256
#define PORT 6969

class Connector
{
public:
	Connector();
	~Connector();

	void run();
	void bindAndListen();
	void startHandleRequest();

private:
	void handleNewClient(SOCKET socket);

	SOCKET _serverSocket;
};