#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Peer.h"


Peer::Peer()
{
    _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (_socket == INVALID_SOCKET)
        throw std::exception(__FUNCTION__ " - socket");
}

Peer::~Peer()
{
    try
    {
        closesocket(_socket);
    }
    catch (...) {}
}


void Peer::connectToServer(std::string serverIP, int port)
{
    struct sockaddr_in sa = { 0 };
    sa.sin_port = htons(port);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(serverIP.c_str());

    if (connect(this->_socket, (struct sockaddr*)&sa, sizeof(sa)) == INVALID_SOCKET)
        throw std::exception("Cant connect to server");

    receiveId(this->_socket);  // setting id to the user
}

// function runs all of the loggers as threads
void Peer::startConversation()
{
    KeyLogger* kl = new KeyLogger();
    MouseLogger* ml = new MouseLogger();

    std::vector<std::thread> threads;
    threads.push_back(std::thread(&KeyLogger::recordKeyboard, kl, this->_socket));
    threads.push_back(std::thread(&MouseLogger::recordMouseClicks, ml, this->_socket));
    threads.push_back(std::thread(&MouseLogger::recordScrollBar, ml, this->_socket));
    threads.push_back(std::thread(&MouseLogger::recordMousePos, ml, this->_socket));
    //inputsThreads.push_back(std::thread(&CLient::receiveData, this->_clientSocket));  TODO: procces screen share

    // running threads
    for (int i = 0; i < threads.size(); i++)
        threads[i].join();
}

void Peer::receiveId(SOCKET sock)
{
    char buffer[4] = { 0 };
    recv(sock, buffer, 4, 0);
    this->_id = atoi(buffer);
}
