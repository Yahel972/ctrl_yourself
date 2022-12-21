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

void Server::connectToServer(std::string serverIP, int port)
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(port); // port that server will listen to
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = inet_addr(serverIP.c_str());    // the IP of the server

	// the process will not continue until the server accepts the client
	int status = connect(this->_serverSocket, (struct sockaddr*)&sa, sizeof(sa));

	if (status == INVALID_SOCKET)
		throw std::exception("Cant connect to server");
}


// function runs all of the loggers - as threads
void Server::startConversation()
{
	//ScreenCapture* sc = new ScreenCapture();

	std::vector<std::thread> inputsThreads;
	//inputsThreads.push_back(std::thread(&ScreenCapture::recordScreen, sc, this->_clientSocket));
	inputsThreads.push_back(std::thread(&Server::receiveData, this->_serverSocket));

	for (int i = 0; i < inputsThreads.size(); i++)
		inputsThreads[i].join();
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


void Server::receiveData(SOCKET clientSocket)
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
			message->updateServer();  // updating the server (controlled pc)

		std::fill_n(buffer, BUFFER_SIZE, 0);  // clearing buffer
		Sleep(30);
	}
}
