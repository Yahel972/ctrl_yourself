#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>


class MouseLogger
{
public:
	MouseLogger();
	~MouseLogger();

	void recordMouse();

private:

};
