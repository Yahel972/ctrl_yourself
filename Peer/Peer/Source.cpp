#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include "Peer.h"
#include <iostream>
#include <exception>

#define SERVER_PORT 6969
#define SERVER_IP "192.168.1.139"

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Peer p;
		p.connectToServer(SERVER_IP, SERVER_PORT, true);
		p.setType();  // controlling/controlled PC

		p.startConversation();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}