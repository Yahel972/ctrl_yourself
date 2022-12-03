#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

class Message
{
public:
	Message();
	Message(std::string content);
	~Message();

	virtual void update_server() = 0;

private:
	std::string _content;
};
