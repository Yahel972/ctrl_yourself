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
        throw std::exception("Cant connect to the Connector");

    std::cout << "Connected with id=" << receiveId(this->_socket) << std::endl;  // setting id to the user
}

// function runs all of the loggers as threads
void Peer::startConversation()
{
    std::vector<std::thread> threads;
    threads.push_back(std::thread(&Peer::receiveData, this, this->_socket));  // no need to put this line in a statement, because both peers need to recive data and procces it (in different ways)

    if (this->_type)  // controller PC
    {
        KeyLogger* kl = new KeyLogger();
        MouseLogger* ml = new MouseLogger();

        threads.push_back(std::thread(&KeyLogger::recordKeyboard, kl, this->_socket));
        threads.push_back(std::thread(&MouseLogger::recordMouseClicks, ml, this->_socket));
        threads.push_back(std::thread(&MouseLogger::recordScrollBar, ml, this->_socket));
        threads.push_back(std::thread(&MouseLogger::recordMousePos, ml, this->_socket));
        //inputsThreads.push_back(std::thread(&Peer::receiveData, this->_clientSocket));  TODO: procces SCREEN SHARE
    }
    else  // controlled PC
    {
        //threads.push_back(std::thread(&ScreenCapture::recordScreen, sc, this->_socket));  TODO: put SCREEN SHARE in this function
    }

    // running all threads
    for (int i = 0; i < threads.size(); i++)
        threads[i].join();
}

void Peer::receiveData(SOCKET sock)
{
    if (this->_type)
    {
        // TODO: fill the data recive for a controller pc
    }
    else
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
}


// function returns the matchin message type according to the content
// TODO - improve that!
Message* Peer::setMessageType(std::string msg)
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


// temporary function - after adding GUI we will update that to not requesting an input (will be set according to the GUI's buttons
void Peer::setType()
{
    int choice = 0;
    std::cout << "Enter 0 to be a controlled pc, or any other key to be a controller pc (TEMPORARY-WILL BE CHANGED AFTER ADDING GUI):\n";
    
    std::cin >> choice;
    this->_type = choice;  // will be true for a non-zero value, false for 0
}


int Peer::receiveId(SOCKET sock)
{
    char buffer[4] = { 0 };
    recv(sock, buffer, 4, 0);

    this->_id = atoi(buffer);
    return this->_id;
}