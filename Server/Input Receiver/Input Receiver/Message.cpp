#include "Message.h"

Message::Message(): _content("") {}

Message::Message(std::string content): _content(content) {}

Message::~Message() {}