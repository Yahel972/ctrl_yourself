#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage(): Message("") {}

KeyboardMessage::KeyboardMessage(std::string content): Message(content)
{
	if (content.length() == 1)  // non special character (such as an 'A' keyboard click)
	{
		this->_key = content;
		this->_isSpecial = false;  // non-special character
	}
	else  // special character (such as <f3> key)
	{
		// extracting key only (without the '<>', will make the updateServer() function be easier)
		std::string tempStr = content;
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '<'), tempStr.end());
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '>'), tempStr.end());

		this->_key = tempStr;
		this->_isSpecial = true;  // special character
	}
}

KeyboardMessage::~KeyboardMessage() {}

void KeyboardMessage::update_server()
{
	if (this->_key == "")  // checking for invalid message
	{
		delete this;
		return;
	}

	if (this->_isSpecial)  // special character
	{
		// TODO: perform the correct action, use switch-case and check the key to distinguishe each seperate key with '-'
		// send the same as the else section, but use the VK consts! https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
	}
	else  // non special character
	{
		if (int(this->_key[0]) >= 32 || int(this->_key[0]) <= 126)  // checking bounds - maybe Ill change it later
		{
			INPUT ip;

			// setting up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			ip.ki.wVk = this->_key[0];  // inserting the key's value to be pressed
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}
