#include "MousePosMessage.h"

MousePosMessage::MousePosMessage() : Message(""), _x(0), _y(0) {}

MousePosMessage::MousePosMessage(std::string content) : Message(content)
{
	// slicing x&y coordinations:
	this->_x = atoi(content.substr(1, content.find('x')).c_str());
	this->_y = atoi(content.substr(content.find('x') + 1, content.find('>')).c_str());
}

MousePosMessage::MousePosMessage(std::string content, int x, int y) : Message(content), _x(x), _y(y) {}

MousePosMessage::~MousePosMessage() {}

void MousePosMessage::updateScreen()
{
	SetCursorPos(this->_x, this->_y);
	Sleep(30);
}
