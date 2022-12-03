#include "KeyLogger.h"

KeyLogger::KeyLogger() {}

KeyLogger::~KeyLogger() {}


// function listens to all keyboard clicks. Will be used as a thread
void KeyLogger::recordKeyboard()
{
	while (true)
	{
		// TODO: spot keyboard clicks

		// TODO: send those clicks to the server - use locks
	}
}
