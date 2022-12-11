#pragma once
#include "Message.h"
#include <algorithm>
#include <sstream>

class KeyboardMessage : public Message
{
public:
	KeyboardMessage();
	KeyboardMessage(std::string content);
	~KeyboardMessage();

	void update_server() override;

private:
	std::string _key;
	bool _isSpecial;  // if the key pressed is a special character or not
};
