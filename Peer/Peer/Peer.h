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
#include <iphlpapi.h>

#include <winsock2.h>


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
	void sendPeerDetails(SOCKET sock);
	std::string receivePeedDetails(SOCKET sock, int peerId);
	int receiveId(SOCKET sock);
	Message* setMessageType(std::string msg);
	void sendMessages(std::string width, std::string height);
	std::string getMyIp();
	std::vector<std::string> seperateBySign(std::string input, std::string sign);


	SOCKET _socket;
	int _id;
	bool _type;  // true - controller, false - being controlled

	int _peerStreamResWidth;
	int _peerStreamResHeight;
		
};