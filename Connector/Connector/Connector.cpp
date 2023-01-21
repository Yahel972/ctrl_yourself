#include "Connector.h"

int Connector::ID_COUNTER = 1;

Connector::Connector()
{
	this->_listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (this->_listener == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Connector::~Connector()
{
	try
	{
		closesocket(this->_listener);
	}
	catch (...) {}
}

void Connector::run()
{
	std::thread t(&Connector::bindAndListen, this);  // creating server
	t.detach();

	std::string userInput = "";
	while (userInput != "EXIT")
	{
		std::cin >> userInput;
	}

}

void Connector::bindAndListen()
{
	std::cout << "Starting..." << std::endl;
	this->_listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // new Socket

	if (this->_listener == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");

	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);  // port that server will listen for
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;  // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(this->_listener, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	std::cout << "Binded" << std::endl;

	// Start listening for incoming requests of clients
	if (listen(this->_listener, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");

	startHandleRequest();
}

void Connector::startHandleRequest()
{
	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		SOCKET conversationSocket = accept(this->_listener, NULL, NULL);
		if (conversationSocket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		this->_connections[generateId(conversationSocket)] = conversationSocket;  // inserting to map - <id,socket>

		std::cout << "Client accepted. Server and client can speak" << std::endl;
		
		// thread for each client:
		std::thread clientThread(&Connector::handleNewClient, this, conversationSocket);
		clientThread.detach();
	}
}

void Connector::handleNewClient(SOCKET sock)
{
	char buffer[SIZE] = { 0 };

	while (true)
	{
		recv(sock, buffer, SIZE, 0);
		std::string msg(buffer);

		if (msg.length() != 0)
		{
			std::cout << msg << std::endl;

			// CURRENTLY - sending to all different users. will be changed after adding GUI
			for (int i = 0; i < this->_connections.size(); i++)
			{
				if (this->_connections[i] != sock)  // to make sure not sending to ourselves
					send(this->_connections[i], buffer, SIZE, 0);
			}
		}

		std::fill_n(buffer, SIZE, 0);  // clearing buffer
	}
}

int Connector::generateId(SOCKET sock)
{
	send(sock, (std::to_string(Connector::ID_COUNTER)).c_str(), 4, 0);
	Connector::ID_COUNTER++;

	return ID_COUNTER - 1;
}
