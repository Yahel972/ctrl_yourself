#pragma once
#include "Message.h"

class KeyboardMessage : Message
{
public:
	KeyboardMessage();
	KeyboardMessage(std::string content);
	~KeyboardMessage();

	void update_server() override;

private:
	std::string _key;
};
