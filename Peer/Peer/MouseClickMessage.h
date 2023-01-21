#pragma once
#include "Message.h"

#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define SCROLL_WHEEL_CLICK 3
#define SCROLL_WHEEL_UP 4
#define SCROLL_WHEEL_DOWN 5
#define INVALID_CODE 0

class MouseClickMessage : public Message
{
public:
	MouseClickMessage();
	MouseClickMessage(std::string content);
	MouseClickMessage(std::string content, int code);
	~MouseClickMessage();

	void updateServer() override;

private:
	int _code;
	/*
	1 - left click
	2 - right click
	3 - scroll click
	4 - scroll up
	5 - scroll down
	0 - invalid (-> destroy message)
	*/
};
