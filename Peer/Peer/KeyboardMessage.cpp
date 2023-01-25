#include "KeyboardMessage.h"

KeyboardMessage::KeyboardMessage() : Message("") {}

KeyboardMessage::KeyboardMessage(std::string content) : Message(content)
{
	if (content.length() == 1)  // non special character (such as an 'A' keyboard click)
	{
		this->_key = content;
		this->_isSpecial = false;
	}
	else  // special character (such as <f3> key)
	{
		// extracting key only (without the '<>', will make the updateServer() function be easier)
		std::string tempStr = content;
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '<'), tempStr.end());
		tempStr.erase(std::remove(tempStr.begin(), tempStr.end(), '>'), tempStr.end());

		this->_key = tempStr;
		this->_isSpecial = true;
	}
}

KeyboardMessage::~KeyboardMessage() {}

void KeyboardMessage::updateScreen()
{
	if (this->_key == "")  // checking for invalid message
	{
		delete this;  // is needed?
		return;
	}

	if (this->_isSpecial)  // special character
	{
		// TODO: perform the correct action, use switch-case and check the key to distinguishe each seperate key with '-'
		// send the same as the else section, but use the VK consts! https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
		// WORD's vector - add each VK const wanted to be pressed. than loop through it and perform each VK's action
	}
	else  // non special character
	{
		if (int(this->_key[0]) >= 32 || int(this->_key[0]) <= 126)  // checking bounds - maybe Ill change it later
		{
			INPUT ip;

			// setting up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = (this->_key[0] < 65 || this->_key[0] > 90) ? 0 : this->_key[0]; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			ip.ki.wVk = (this->_key[0] < 65 || this->_key[0] > 90) ? VkKeyScan(this->_key[0]) : 0; // inserting the key's value to be pressed
			ip.ki.dwFlags = KEYEVENTF_UNICODE; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));
		}
	}
}
