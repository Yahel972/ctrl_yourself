#pragma comment (lib, "ws2_32.lib")

#include "WSAInitializer.h"
#include "Peer.h"
#include <iostream>
#include <exception>

#define SERVER_PORT 6969
#define SERVER_IP "127.0.0.1" //SHOULD CHANGE BASED ON IF THE PC IS CONTROLLING/CONTROLLED

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Peer p;
		p.connectToServer(SERVER_IP, SERVER_PORT);
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