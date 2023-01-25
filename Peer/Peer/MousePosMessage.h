#pragma once
#include "Message.h"

class MousePosMessage : public Message
{
public:
	MousePosMessage();
	MousePosMessage(std::string content);
	MousePosMessage(std::string content, int x, int y);
	~MousePosMessage();

	void updateScreen() override;

private:
	// cursor's coordinates:
	int _x;
	int _y;
};
