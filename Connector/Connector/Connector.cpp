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

		this->_connections.push_back(client_socket);
		sendId(client_socket);

		std::cout << "Client accepted. Server and client can speak" << std::endl;
		//this->m_clients[client_socket] = this->m_handlerFactory.createLoginRequest();
		// the function that handle the conversation with the client
		std::thread clientThread(&Connector::handleNewClient, this, client_socket); // thread for each client
		clientThread.detach(); // no need to wait for client thread to end, it can run until the client logs out 
	}
}

void Connector::handleNewClient(SOCKET socket)
{
	// checking if the new RequestInfo is relevent 
	// if the RequestInfo IS relevent, handle it
	// receving data 
	while (true) // keeping communication alive
	{
		// reciving message
		char recivedData[MAX_SIZE] = { 0 };
		recv(socket, recivedData, MAX_SIZE, 0);

		// handeling the request
		//if (this->m_clients[socket]->isRequestRelevant(requestInfo)) // checking if the given request is valid based on the current state of the user 
		//{
		//	RequestResult result = this->m_clients[socket]->handleRequest(requestInfo); // handleing requset

		//	// switching (or, not switching) the current state of the user
		//	if (result.newHandler != nullptr)
		//	{
		//		delete this->m_clients[socket];
		//		this->m_clients[socket] = result.newHandler;
		//	}

		//	// sending the response back to the client
		//	std::stringstream responseStream;
		//	for (int i = 0; i < result.response.size(); i++)
		//	{
		//		responseStream << result.response[i];
		//	}
		//	send(socket, responseStream.str().c_str(), responseStream.str().size(), 0);
		//}
		//else  // invalid request for the current state 
		//{
		//	// building and sending error message
		//	ErrorResponse errorResponse;
		//	errorResponse.message = "ERROR wrong code (" + std::to_string(requestInfo.id) + ") for current state";
		//	std::vector<unsigned char> serializedResponse = JsonResponsePacketSerializer::serializeResponse(errorResponse);
		//	std::stringstream responseStream;
		//	for (int i = 0; i < serializedResponse.size(); i++)
		//	{
		//		responseStream << serializedResponse[i];
		//	}
		//	send(socket, responseStream.str().c_str(), responseStream.str().size(), 0);
		//}
	}

}

void Connector::sendId(SOCKET sock)
{
	send(sock, (std::to_string(Connector::ID_COUNTER)).c_str(), 4, 0);
	Connector::ID_COUNTER++;
}
