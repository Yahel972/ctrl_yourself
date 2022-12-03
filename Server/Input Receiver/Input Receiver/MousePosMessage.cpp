#include "MousePosMessage.h"

MousePosMessage::MousePosMessage(): Message(""), _x(0), _y(0) {}

MousePosMessage::MousePosMessage(std::string content): Message(content)
{
	// TODO: extract x&y's coordinations
}

MousePosMessage::MousePosMessage(std::string content, int x, int y): Message(content), _x(x), _y(y) {}

MousePosMessage::~MousePosMessage() {}

void MousePosMessage::update_server()
{
	SetCursorPos(this->_x, this->_y);
	Sleep(30);
}
