#pragma comment (lib, "ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include "WSAInitializer.h"
#include "Client.h"
#include <exception>
#include <iostream>

#define SERVER_PORT 6969
#define SERVER_IP "127.0.0.1"

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Client c;
		c.connectToServer(SERVER_IP, SERVER_PORT);
		c.startConversation();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}