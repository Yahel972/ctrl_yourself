#pragma once
#include <string>

class Message
{
public:
	Message();
	Message(std::string content);
	~Message();

	virtual void update_server() = 0;

private:
	std::string _content;
};
