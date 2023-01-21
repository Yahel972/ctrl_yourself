#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include "KeyLogger.h"
#include "MouseLogger.h"
#include <exception>
#include <iostream>
#include <vector>

class Peer
{
public:
	Peer();
	~Peer();

	void connectToServer(std::string serverIP, int port);
	void startConversation();

private:
	//void receiveData(SOCKET sock);  LATER - after screen share
	void receiveId(SOCKET sock);

	SOCKET _socket;
	int _id;
};