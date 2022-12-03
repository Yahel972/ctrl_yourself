#include "MouseLogger.h"

MouseLogger::MouseLogger() {}

MouseLogger::~MouseLogger() {}

// helper function - returns if a specific key has been pressed
int keyPressed(int key) {
	return (GetAsyncKeyState(key) & 0x8000 != 0);
}

// function listens to all mouse clicks & position changes. Will be used as a thread
void MouseLogger::recordMouseClicks()
{
	while (true)
	{
		if (GetAsyncKeyState(WM_LBUTTONDOWN))
		{
			std::cout << "<double-click>";
		}
		if (keyPressed(MK_LBUTTON))
		{
			std::cout << "<left-click>";
		}
		else if (keyPressed(VK_RBUTTON))
		{
			std::cout << "<right-click>";
		}
	}
}

// function returns if 2 POINTS are equal
bool compareCoordinates(POINT a, POINT b) {	return (a.x == b.x && a.y == b.y); }

void MouseLogger::recordMousePos()
{
	POINT currPos;
	POINT tempPos;
	
	GetCursorPos(&currPos);
	while (true)
	{
		GetCursorPos(&tempPos);
		if (!compareCoordinates(currPos, tempPos))
		{
			currPos = tempPos;

			// TODO: send currPos to Server (2nd user)
			std::cout << "<" << currPos.x << "x" << currPos.y << ">";
			Sleep(2000);  // just for now, in order to reduce non-stop printing
		}
	}
}
