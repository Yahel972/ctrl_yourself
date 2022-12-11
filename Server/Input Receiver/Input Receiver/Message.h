#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include "MouseClickMessage.h"
#include "MousePosMessage.h"
#include "KeyboardMessage.h"
#include <regex>

class Message
{
public:
	Message();
	Message(std::string content);
	~Message();

	virtual void update_server() = 0;
	
	static Message* setMessageType(std::string msg);
private:
	std::string _content;
};
