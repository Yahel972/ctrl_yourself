#include "Server.h"


Server::Server()
{
	_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Server::~Server()
{
	try
	{
		closesocket(_serverSocket);
	}
	catch (...) {}
}

void Server::connectToServer(std::string serverIP, int port)
{
	struct sockaddr_in sa = { 0 };
	sa.sin_port = htons(port);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr(serverIP.c_str());

	int status = connect(this->_serverSocket, (struct sockaddr*)&sa, sizeof(sa));
	if (status == INVALID_SOCKET)
		throw std::exception("Cant connect to server");

	receiveId(this->_serverSocket);  // setting id to the user
}


// function runs all of the loggers as threads
void Server::startConversation()
{
	//ScreenCapture* sc = new ScreenCapture(); TODO: add screen capture

	std::vector<std::thread> inputsThreads;
	//inputsThreads.push_back(std::thread(&ScreenCapture::recordScreen, sc, this->_clientSocket));  TODO: put SCREEN SHARE in this function
	inputsThreads.push_back(std::thread(&Server::receiveData, this, this->_serverSocket));

	// running threads:
	for (int i = 0; i < inputsThreads.size(); i++)
		inputsThreads[i].join();
}

// function returns the matchin message type according to the content
// TODO - improve that!
Message* Server::setMessageType(std::string msg)
{
	if (std::regex_match(msg, std::regex("<[0-9]+x[0-9]+>")))
	{
		return new MousePosMessage(msg);  // the constructor will extract the coordinations by itself
	}
	else if (msg == "<left-click>" || msg == "<right-click>" || msg == "<scroll-click>" || msg == "<scroll-up>" || msg == "<scroll-down>")
	{
		return new MouseClickMessage(msg);
	}
	else if (msg.length() > 0)  // Keyboard msg - not any other type exists
	{
		return new KeyboardMessage(msg);
	}

	return NULL;
}


void Server::receiveData(SOCKET sock)
{
	char buffer[BUFFER_SIZE] = { 0 };

	while (true)
	{
		recv(sock, buffer, BUFFER_SIZE, 0);
		std::string msg(buffer);

		if (msg.length() != 0)
			std::cout << msg << std::endl;

		// creating message and performing the appropriate response:
		Message* message = setMessageType(msg);
		if (message != NULL)
			message->updateServer();

		std::fill_n(buffer, BUFFER_SIZE, 0);  // clearing buffer
		Sleep(30);
	}
}

void Server::receiveId(SOCKET sock)
{
	char buffer[4] = { 0 };
	recv(sock, buffer, 4, 0);
	this->_id = atoi(buffer);
}
