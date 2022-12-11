#include "Server.h"


Server::Server()
{

	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Server::~Server()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Server::serve(int port)
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << port << std::endl;

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		acceptClient();
	}
}

// function returns the matchin message type according to the content
Message* Server::setMessageType(std::string msg)
{
	if (std::regex_match(msg, std::regex("<[0-9]+x[0-9]+>")))
	{
		return new MousePosMessage(msg);  // the constructor will extract the coordinations by itself
	}
	else if (msg == "<left-click>" || msg == "<right-click>" || msg == "<scroll-wheel-click>" || msg == "<scroll-wheel-up>" || msg == "<scroll-wheel-down>")
	{
		return new MouseClickMessage(msg);
	}
	else if (msg.length() > 0)  // Keyboard msg - not any other type exists
	{
		return new KeyboardMessage(msg);
	}

	return NULL;
}


void Server::acceptClient()
{
	// this accepts the client and create a specific socket from server to this client
	// the process will not continue until a client connects to the server
	SOCKET client_socket = accept(_serverSocket, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::cout << "Client accepted. Server and client can speak" << std::endl;
	// the function that handle the conversation with the client
	clientHandler(client_socket);
}


void Server::clientHandler(SOCKET clientSocket)
{
	char buffer[BUFFER_SIZE] = { 0 };

	while (true)
	{
		recv(clientSocket, buffer, BUFFER_SIZE, 0);
		std::string msg(buffer);

		if (msg.length() != 0)
			std::cout << msg << std::endl;

		// creating message and performing the appropriate response
		Message* message = setMessageType(msg);
		if (message != NULL)
			message->update_server();  // updating the server (controlled pc)

		std::fill_n(buffer, BUFFER_SIZE, 0);  // clearing buffer
		Sleep(30);
	}
}
