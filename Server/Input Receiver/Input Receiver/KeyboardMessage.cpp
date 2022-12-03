#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage(): Message("") {}

KeyboardMessage::KeyboardMessage(std::string content): Message(content)
{
	// TODO: extract the key
	// first check if there are <> in the content/length is bigger than 1 - if not its not a special character
}

KeyboardMessage::~KeyboardMessage() {}

void KeyboardMessage::update_server()
{
	// TODO: use the key
}
