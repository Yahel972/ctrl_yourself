#pragma once
#include "Message.h"

class MousePosMessage : public Message
{
public:
	MousePosMessage();
	MousePosMessage(std::string content);
	MousePosMessage(std::string content, int x, int y);
	~MousePosMessage();

	void updateServer() override;

	static float MOUSE_MOVE_FACTOR;
private:
	int _x;
	int _y;
	// cursor's coordinates

	static float getMouseMoveFactor();
};
