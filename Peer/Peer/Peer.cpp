#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Peer.h"
#include "WSAInitializer.h"
#include "PeerServer.h"

Peer::Peer()
{
    this->_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (this->_socket == INVALID_SOCKET)
        throw std::exception(__FUNCTION__ " - socket");
}

Peer::~Peer()
{
    try
    {
        closesocket(this->_socket);
    }
    catch (...) {}
}

void Peer::connectToServer(std::string serverIP, int port)
{
    struct sockaddr_in sa = { 0 };
    sa.sin_port = htons(port);
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(serverIP.c_str());

    // trying to connect to the connector:
    if (connect(this->_socket, (struct sockaddr*)&sa, sizeof(sa)) == INVALID_SOCKET)
        throw std::exception("Cant connect to the Connector");

    std::cout << "Connected with id=" << receiveId(this->_socket) << std::endl;  // setting an id to the user
}

// function runs all of the loggers & receivers as threads
void Peer::startConversation()
{
    std::vector<std::thread> threads;

    if (this->_type)  // controlling PC
    {
        // init server
        try
        {
            WSAInitializer wsaInit;
            PeerServer p;

            p.run();
        }
        catch (std::exception& e)
        {
            std::cout << "Error occured: " << e.what() << std::endl;
        }
    }
    else  // controlled PC
    {
        Peer peer2peer;
        peer2peer.connectToServer("127.0.0.1", 5471);
        peer2peer.sendMessages();

    }

    // running all threads
    for (int i = 0; i < threads.size(); i++)
        threads[i].join();
}

// function receives keyboard & mouse loggers - and updates the screen according to them inputs
void Peer::receiveRecords(SOCKET sock)
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
            message->updateScreen();

        std::fill_n(buffer, BUFFER_SIZE, 0);  // clearing buffer
        Sleep(10);
    }
}

// function returns the matching message type according to the content
// TODO - improve that! - after adding PROTOCOL
Message* Peer::setMessageType(std::string msg)
{
    if (std::regex_match(msg, std::regex("<[0-9]+x[0-9]+>")))
    {
        return new MousePosMessage(msg);  // the constructor will extract the coordinations by itself
    }
    else if (msg == "<left-click>" || msg == "<right-click>" || msg == "<scroll-click>" || msg == "<scroll-up>" || msg == "<scroll-down>")
    {
        return new MouseMessage(msg);
    }
    else if (msg.length() > 0)  // Keyboard msg - not any other type exists
    {
        return new KeyboardMessage(msg);
    }

    return NULL;
}

void Peer::sendMessages()
{
    std::vector<std::thread> threads;

    ScreenCapture* sc = new ScreenCapture();
    threads.push_back(std::thread(&ScreenCapture::recordScreen, sc, this->_socket));  // logger

    threads.push_back(std::thread(&Peer::receiveRecords, this, this->_socket));  // receiver

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}


// temporary function - after adding GUI we will update that to not requesting an input (will be set according to the GUI's buttons and the state of the call)
void Peer::setType()
{
    int choice = 0;
    std::cout << "Enter 0 to be a controlled pc, or any other key to be a controlling pc (TEMPORARY-WILL BE CHANGED AFTER ADDING GUI):\n";
    
    std::cin >> choice;
    this->_type = choice;  // will be true for a non-zero value, false for 0
}

// function receives an id from the connector
int Peer::receiveId(SOCKET sock)
{
    char buffer[4] = { 0 };
    recv(sock, buffer, 4, 0);

    this->_id = atoi(buffer);
    return this->_id;
}