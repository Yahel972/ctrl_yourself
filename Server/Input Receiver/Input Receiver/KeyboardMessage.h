#pragma once
#include "Message.h"
#include <algorithm>

class KeyboardMessage : public Message
{
public:
	KeyboardMessage();
	KeyboardMessage(std::string content);
	~KeyboardMessage();

	void update_server() override;

private:
	std::string _key;
};
