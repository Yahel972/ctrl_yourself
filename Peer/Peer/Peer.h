#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include "KeyLogger.h"
#include "MouseLogger.h"
#include "ScreenCapture.h"
#include <exception>
#include <iostream>
#include <vector>
#include <thread>
#include "MouseMessage.h"
#include "MousePosMessage.h"
#include "KeyboardMessage.h"
#include <regex>

#define BUFFER_SIZE 256

class Peer
{
public:
	Peer();
	~Peer();

	void connectToServer(std::string serverIP, int port);
	void startConversation();
	void setType();

private:
	void receiveRecords(SOCKET sock);
	int receiveId(SOCKET sock);
	Message* setMessageType(std::string msg);
	void sendMessages();

	SOCKET _socket;
	int _id;
	bool _type;  // true - controller, false - being controlled
};