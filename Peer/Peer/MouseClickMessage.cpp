#include "MouseClickMessage.h"

MouseClickMessage::MouseClickMessage() : Message(""), _code(INVALID_CODE) {}

MouseClickMessage::MouseClickMessage(std::string content) : Message(content)
{
	// setting message's code:
	if (content == "<left-click>")
		this->_code = LEFT_CLICK;
	else if (content == "<right-click>")
		this->_code = RIGHT_CLICK;
	else if (content == "<scroll-click>")
		this->_code = SCROLL_WHEEL_CLICK;
	else if (content == "<scroll-up>")
		this->_code = SCROLL_WHEEL_UP;
	else if (content == "<scroll-down>")
		this->_code = SCROLL_WHEEL_DOWN;
	else
		this->_code = INVALID_CODE;
}

MouseClickMessage::MouseClickMessage(std::string content, int code) : Message(content), _code(code) {}

MouseClickMessage::~MouseClickMessage() {}

void MouseClickMessage::updateServer()
{
	INPUT input = { 0 };

	switch (this->_code)
	{
	case LEFT_CLICK:
		// left down 
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		SendInput(1, &input, sizeof(INPUT));

		// left up
		ZeroMemory(&input, sizeof(INPUT));
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		SendInput(1, &input, sizeof(INPUT));
		break;

	case RIGHT_CLICK:
		// Right down 
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		SendInput(1, &input, sizeof(INPUT));

		// Right up
		ZeroMemory(&input, sizeof(INPUT));
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		SendInput(1, &input, sizeof(INPUT));
		break;

	case SCROLL_WHEEL_CLICK:
		// Middle down 
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		SendInput(1, &input, sizeof(INPUT));

		// Middle up
		ZeroMemory(&input, sizeof(INPUT));
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
		SendInput(1, &input, sizeof(INPUT));
		break;

	case SCROLL_WHEEL_UP:
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_WHEEL;
		input.mi.mouseData = WHEEL_DELTA;
		SendInput(1, &input, sizeof(INPUT));
		break;

	case SCROLL_WHEEL_DOWN:
		input.type = INPUT_MOUSE;
		input.mi.dwFlags = MOUSEEVENTF_WHEEL;
		input.mi.mouseData = -WHEEL_DELTA;
		SendInput(1, &input, sizeof(INPUT));
		break;

	case INVALID_CODE:
		delete this;
		break;
	}
}
