#pragma comment (lib, "ws2_32.lib")
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "WSAInitializer.h"
#include "Peer.h"
#include <iostream>
#include <exception>
#include "LoginForm.h"

#define SERVER_PORT 6969
#define SERVER_IP "192.168.1.139"

using namespace System;
using namespace System::Windows::Forms;
using namespace Client;

int main()
{
	try
	{
		WSAInitializer wsaInit;
		Peer p;
		p.connectToServer(SERVER_IP, SERVER_PORT, true);
		//p.setType();  // controlling/controlled PC

		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		LoginForm form;
		Application::Run(% form);

		p.startConversation();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occured: " << e.what() << std::endl;
	}
	system("PAUSE");
	return 0;
}