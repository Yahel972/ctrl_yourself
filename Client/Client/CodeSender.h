#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>

class CodeSender
{
private:
	static int generateCode();
	static LPCWSTR toLPCWSTR(const char* cc);

public:
	static int sendCode(const std::string email, const std::string name);
};

