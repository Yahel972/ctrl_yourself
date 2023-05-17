#pragma comment (lib, "ws2_32.lib")

#include <WinSock2.h>
#include <Windows.h>
#include "WSAInitializer.h"
#include "Connector.h"
#include <exception>

int main()	
{

	try
	{
		WSAInitializer wsaInit;
		Connector c;

		c.run();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}