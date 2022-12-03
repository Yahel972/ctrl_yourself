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


void MouseLogger::recordMousePos()
{
	while (true)
	{
		// TODO: spot mouse clicks

		// TODO: send those clicks to the server - use locks
	}
}
