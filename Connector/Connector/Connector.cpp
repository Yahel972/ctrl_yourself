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

// function initializes a socket
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

// function waits for a user to connect
// then gives him an id and calls a handler for him
void Connector::startHandleRequest()
{
	while (true)
	{
		// waiting for connection
		std::cout << "Waiting for connection request" << std::endl;
		SOCKET conversationSocket = accept(this->_listener, NULL, NULL);
		if (conversationSocket == INVALID_SOCKET)
			throw std::exception(__FUNCTION__);

		// user connected - generating id:
		int id = generateId(conversationSocket);
		this->_connections[id] = conversationSocket;  // inserting to map - <id,socket>
		std::cout << "Client accepted (id=" << id << "). Server and client can speak" << std::endl;
		
		// creating a handler thread for the user:
		std::thread clientThread(&Connector::handleNewClient, this, conversationSocket);
		clientThread.detach();
	}
}

// function handles a new client
void Connector::handleNewClient(SOCKET sock)
{
	// after adding GUI, this function will transfer messages only between the 2 peers having a takeover call


	while (true)
	{
		char* buffer = new char[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = 0;
		}
		recv(sock, buffer, SIZE, 0);
		std::string msg(buffer);

		if (msg.length() != 0)
		{
			std::cout << msg;
			//std::cout << msg << std::endl;
			// TODO: check if not an image/Mat before printing
			// can be done after adding protocol

			// CURRENTLY - sending to all of the users. will be changed after adding GUI
			for (int i = 0; i < this->_connections.size(); i++)
			{
				if (this->_connections[i] != sock)  // to make sure not sending to ourselves
					send(this->_connections[i], buffer, SIZE, 0);
			}
		}
		delete[] buffer;
	}
}

// function generates an id for a new user
int Connector::generateId(SOCKET sock)
{
	send(sock, (std::to_string(Connector::ID_COUNTER)).c_str(), 4, 0);
	Connector::ID_COUNTER++;

	return ID_COUNTER - 1;
}
