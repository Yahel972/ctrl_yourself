#pragma once
#include "Message.h"

#define LEFT_CLICK 1
#define RIGHT_CLICK 2
#define SCROLL_WHEEL_CLICK 3
#define SCROLL_WHEEL_MOVE 4

class MouseClickMessage : Message
{
public:
	MouseClickMessage();
	MouseClickMessage(std::string content);
	MouseClickMessage(std::string content, int code);
	~MouseClickMessage();

	void update_server() override;

private:
	int _code;
	/*
	1 - left click
	2 - right click
	3 - scroll wheel click
	4 - scroll wheel move (up/down)
	0 - invalid (-> destroy message)
	*/
};
