#include "MouseClickMessage.h"

MouseClickMessage::MouseClickMessage(): Message(""), _code(0){}

MouseClickMessage::MouseClickMessage(std::string content): Message(content)
{
	// TODO: set the code
}

MouseClickMessage::MouseClickMessage(std::string content, int code): Message(content), _code(code) {}

MouseClickMessage::~MouseClickMessage() {}

void MouseClickMessage::update_server()
{
	// TODO perform the click
}
