#include "Connector.h"

int Connector::ID_COUNTER = 0;

Connector::Connector()
{
	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	this->_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (this->_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Connector::~Connector()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(this->_serverSocket);
	}
	catch (...) {}
}

void Connector::run()
{
	std::thread t_connector(&Connector::bindAndListen, this);  // creating server
	t_connector.detach();

	std::string userInput = "";
	while (userInput != "EXIT")
	{
		std::cin >> userInput;
	}

}

void Connector::bindAndListen()
{
	std::cout << "Starting..." << std::endl;
	this->_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // new Socket

	if (this->_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");

	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(PORT);  // port that server will listen for
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;  // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(this->_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	std::cout << "Binded" << std::endl;

	// Start listening for incoming requests of clients
	if (listen(this->_serverSocket, SOMAXCONN) == SOCKET_ERROR)
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
		SOCKET client_socket = accept(this->_serverSocket, NULL, NULL);
		if (client_socket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		this->_connections[generateId(client_socket)] = client_socket;  // inserting to map

		std::cout << "Client accepted. Server and client can speak" << std::endl;
		//this->m_clients[client_socket] = this->m_handlerFactory.createLoginRequest();
		// the function that handle the conversation with the client
		std::thread clientThread(&Connector::handleNewClient, this, client_socket); // thread for each client
		clientThread.detach(); // no need to wait for client thread to end, it can run until the client logs out 
	}
}

void Connector::handleNewClient(SOCKET sock)
{
	char buffer[BUFFER_SIZE] = { 0 };

	while (true)
	{
		recv(sock, buffer, BUFFER_SIZE, 0);
		std::string msg(buffer);

		if (msg.length() != 0)
		{
			std::cout << msg << std::endl;

			for (int i = 0; i < this->_connections.size(); i++)
			{
				if (this->_connections[i] != sock)  /// ??????
				{
					send(this->_connections[i], buffer, BUFFER_SIZE, 0);
				}
			}
		}

		std::fill_n(buffer, BUFFER_SIZE, 0);  // clearing buffer
	}
}

int Connector::generateId(SOCKET sock)
{
	send(sock, (std::to_string(Connector::ID_COUNTER)).c_str(), 4, 0);
	Connector::ID_COUNTER++;

	return ID_COUNTER - 1;
}
