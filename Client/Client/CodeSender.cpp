#include "CodeSender.h"

int CodeSender::generateCode()
{
	srand(time(nullptr));
	return (rand() % 9000 + 1000);
}

LPCWSTR CodeSender::toLPCWSTR(const char* cc)
{
	int size = strlen(cc) + 1;
	LPWSTR wideString = new wchar_t[size];
	MultiByteToWideChar(CP_ACP, 0, cc, -1, wideString, size);
	return wideString;
}

int CodeSender::sendCode(const std::string email, const std::string name)
{
	int code = generateCode();

	std::string command_line = "/c code_sender.exe " + email + " " + name + " " + std::to_string(code);
	ShellExecute(NULL, L"open", L"cmd.exe", toLPCWSTR(command_line.c_str()), NULL, SW_HIDE);

	return code;
}
