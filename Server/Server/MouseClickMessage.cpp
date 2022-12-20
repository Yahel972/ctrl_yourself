#include "MouseClickMessage.h"

MouseClickMessage::MouseClickMessage() : Message(""), _code(INVALID_CODE) {}

MouseClickMessage::MouseClickMessage(std::string content) : Message(content)
{
	// setting message's code:
	if (content == "<left-click>")
		this->_code = LEFT_CLICK;
	else if (content == "<right-click>")
		this->_code = RIGHT_CLICK;
	else if (content == "<scroll-wheel-click>")
		this->_code = SCROLL_WHEEL_CLICK;
	else if (content == "<scroll-wheel-up>")
		this->_code = SCROLL_WHEEL_UP;
	else if (content == "<scroll-wheel-down>")
		this->_code = SCROLL_WHEEL_DOWN;
	else
		this->_code = INVALID_CODE;
}

MouseClickMessage::MouseClickMessage(std::string content, int code) : Message(content), _code(code) {}

MouseClickMessage::~MouseClickMessage() {}

void MouseClickMessage::updateServer()
{
	INPUT Input = { 0 };
	POINT p;
	GetCursorPos(&p);

	switch (this->_code)
	{
	case LEFT_CLICK:
		// left down 
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		// left up
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		::SendInput(1, &Input, sizeof(INPUT));
		break;

	case RIGHT_CLICK:
		// Right down 
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		::SendInput(1, &Input, sizeof(INPUT));

		// Right up
		::ZeroMemory(&Input, sizeof(INPUT));
		Input.type = INPUT_MOUSE;
		Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		::SendInput(1, &Input, sizeof(INPUT));
		break;

	case SCROLL_WHEEL_CLICK:
		// TODO: fill this
		break;

	case SCROLL_WHEEL_UP:
		// TODO: fill this
		break;

	case SCROLL_WHEEL_DOWN:
		// TODO: fill this
		break;

	case INVALID_CODE:
		delete this;
		break;
	}
}
