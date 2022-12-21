#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <thread>
#include <map>

#define MAX_SIZE 256
#define PORT 6969
#define BUFFER_SIZE 256

class Connector
{
public:
	Connector();
	~Connector();

	void run();
	void bindAndListen();
	void startHandleRequest();

private:
	void handleNewClient(SOCKET sock);

	SOCKET _serverSocket;
	std::map<int, SOCKET> _connections;

	static int ID_COUNTER;
	static int generateId(SOCKET sock);
};