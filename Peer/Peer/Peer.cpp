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
    this->sendPeerDetails(this->_socket);
}

// function runs all of the loggers & receivers as threads
void Peer::startConversation()
{
    int peerId = 0;
    std::cout << "enter the id of the user: " << std::endl;
    std::cin >> peerId;
    std::string details = receivePeedDetails(this->_socket, peerId);

    std::string value;

    std::istringstream iss(details);
    std::getline(iss, value, '&');
    std::string everyIP = value;

    std::getline(iss, value, '&');
    std::string width = value;

    std::getline(iss, value, '&');
    std::string height = value;

    std::vector<std::string> ipList = this->seperateBySign(everyIP, "|");


    if (this->_type)  // controlling PC
    {

        // init server
        try
        {
            WSAInitializer wsaInit;
            PeerServer p;

            p.run(width, height);
        }
        catch (std::exception& e)
        {
            std::cout << "Error occured: " << e.what() << std::endl;
        }
    }
    else  // controlled PC
    {
        Peer peer2peer;
        for (int i = 0; i < ipList.size(); i++)
        {
            std::cout << "Trying to connect..." << std::endl;
            try
            {
                peer2peer.connectToServer(ipList[i], 5471);
                peer2peer.sendMessages(width, height);
            }
            catch (const std::exception& e)
            {
                std::cout << e.what() << std::endl;
            }
        }
        std::cout << "ERROR" << std::endl;

    }


    // running all threads
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

void Peer::sendPeerDetails(SOCKET sock)
{
    std::string screenWidth = std::to_string(GetSystemMetrics(SM_CXSCREEN));
    std::string screenHeight = std::to_string(GetSystemMetrics(SM_CYSCREEN));
    std::string id = std::to_string(this->_id);
    std::string ip = getMyIp();
    std::string msg = "1&" + id + "&" + ip + "&" + screenWidth + "&" + screenHeight;
    send(sock, msg.c_str(), msg.size(), 0);
}

std::string Peer::receivePeedDetails(SOCKET sock, int peerId)
{
    char details[DETAILS_SIZE] = { 0 };
    std::string id = std::to_string(this->_id);
    std::string msg = "2&" + id + "&" + std::to_string(peerId);
    send(sock, msg.c_str(), msg.size(), 0);

    recv(sock, details, DETAILS_SIZE, 0);
    return std::string(details);
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

void Peer::sendMessages(std::string width, std::string height)
{
    std::vector<std::thread> threads;

    ScreenCapture* sc = new ScreenCapture();
    threads.push_back(std::thread(&ScreenCapture::recordScreen, sc, this->_socket, width, height));  // logger

    threads.push_back(std::thread(&Peer::receiveRecords, this, this->_socket));  // receiver

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}

std::string Peer::getMyIp()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);

    char hostName[256];
    iResult = gethostname(hostName, sizeof(hostName));

    struct hostent* hostInfo = gethostbyname(hostName);

    std::string ip_address_list = "";//inet_ntoa(*(struct in_addr*)hostInfo->h_addr_list[0]);

    for (int i = 0; hostInfo->h_addr_list[i] != nullptr; i++) {
        std::string ipAddress = inet_ntoa(*(struct in_addr*)hostInfo->h_addr_list[i]);
        if (i > 0) {
            ip_address_list += "|";
        }
        ip_address_list += ipAddress;
    }

    std::cout << "IP address of " << hostName << ": " << ip_address_list << std::endl;

    WSACleanup();
    return std::string(ip_address_list);
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

std::vector<std::string> Peer::seperateBySign(std::string input, std::string sign)
{
    std::vector<std::string> output;
    int pos = 0;
    while (pos < input.length()) {
        size_t next_pos = input.find('|', pos);
        if (next_pos == std::string::npos) {
            next_pos = input.length();
        }
        output.push_back(input.substr(pos, next_pos - pos));
        pos = next_pos + 1;
    }
    return output;
}
