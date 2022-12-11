#include "Message.h"

Message::Message(): _content("") {}

Message::Message(std::string content): _content(content) {}

Message::~Message() {}

// function returns the matchin message type according to the content
Message* Message::setMessageType(std::string msg)
{
	if (std::regex_match(msg, std::regex("<[0-9]+x[0-9]+>")))
	{
		return new MousePosMessage(msg);  // the constructor will extract the coordinations by itself
	}
	else if (msg == "<left-click>" || msg == "<right-click>" || msg == "<scroll-wheel-click>" || msg == "<scroll-wheel-up>" || msg == "<scroll-wheel-down>")
	{
		return new MouseClickMessage(msg);
	}
	else if (msg.length() > 0)  // Keyboard msg - not any other type exists
	{
		return new KeyboardMessage(msg);
	}

	return NULL;
}