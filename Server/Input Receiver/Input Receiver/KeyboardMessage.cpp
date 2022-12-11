#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage(): Message("") {}

KeyboardMessage::KeyboardMessage(std::string content): Message(content)
{
	if (content.length() == 1)  // non special character (such as an 'A' keyboard click)
		this->_key = content;
	else  // special character (such as <f3> key)
	{
		std::string tempStr = content;
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '<'), tempStr.end());
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '>'), tempStr.end());
		this->_key = tempStr;
	}
}

KeyboardMessage::~KeyboardMessage() {}

void KeyboardMessage::update_server()
{
	// check if "" - do nothing

	// TODO: use the key
}
