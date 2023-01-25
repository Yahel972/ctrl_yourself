#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>
#include "Peer.h"
#include <WinUser.h>

class MouseLogger
{
public:
	MouseLogger();
	~MouseLogger();

	void recordMouseClicks(SOCKET sock);
	void recordMousePos(SOCKET sock);
	static LRESULT CALLBACK startListen(int nCode, WPARAM wParam, LPARAM lParam);
	void recordScrollBar(SOCKET sock);

private:
	static int keyPressed(int key);
	static bool comparePoints(POINT a, POINT b);
};
