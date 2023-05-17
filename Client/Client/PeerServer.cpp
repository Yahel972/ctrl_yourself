#include "PeerServer.h"

PeerServer::PeerServer()
{
	this->_listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (this->_listener == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

PeerServer::~PeerServer()
{
	try
	{
		closesocket(this->_listener);
	}
	catch (...) {}
}

void PeerServer::run(std::string width, std::string height)
{
	std::thread t(&PeerServer::bindAndListen, this, width, height);  // creating server
	t.detach();

	std::string userInput = "";
	while (userInput != "EXIT")
	{
		std::cin >> userInput;
	}
}

void PeerServer::bindAndListen(std::string width, std::string height)
{
	std::cout << "Starting Session..." << std::endl;
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
	std::cout << "Waiting for connection request" << std::endl;
	SOCKET conversationSocket = accept(this->_listener, NULL, NULL);
	if (conversationSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::thread clientThread(&PeerServer::handleConversation, this, conversationSocket, width, height);
	clientThread.detach();

}

void PeerServer::handleConversation(SOCKET sock, std::string width, std::string height)
{
	std::vector<std::thread> threads;

	KeyLogger* kl = new KeyLogger();
	MouseLogger* ml = new MouseLogger();
	ScreenCapture* sc = new ScreenCapture();

	// loggers:
	threads.push_back(std::thread(&KeyLogger::recordKeyboard, kl, sock));
	threads.push_back(std::thread(&MouseLogger::recordMouseClicks, ml, sock));
	threads.push_back(std::thread(&MouseLogger::recordScrollBar, ml, sock));
	threads.push_back(std::thread(&MouseLogger::recordMousePos, ml, sock));

	threads.push_back(std::thread(&ScreenCapture::receiveCaptures, sc, sock, width, height));  // reciever

	for (int i = 0; i < threads.size(); i++)
		threads[i].join();
}
