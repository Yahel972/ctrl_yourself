#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage(): Message("") {}

KeyboardMessage::KeyboardMessage(std::string content): Message(content)
{
	// TODO: extract the key
}

KeyboardMessage::~KeyboardMessage() {}

void KeyboardMessage::update_server()
{
	// TODO: use the key
}
