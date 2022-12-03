#pragma once
#include "Message.h"

class MousePosMessage : public Message
{
public:
	MousePosMessage();
	MousePosMessage(std::string content);
	MousePosMessage(std::string content, int x, int y);
	~MousePosMessage();

	void update_server() override;

private:
	int _x;
	int _y;
	// cursor's coordinates
};
