#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include "Server.h"
#include <iostream>
#include <exception>

#define SERVER_PORT 6969
#define SERVER_IP "192.168.1.148"

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Server s;
		s.connectToServer(SERVER_IP, SERVER_PORT);
		s.startConversation();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}