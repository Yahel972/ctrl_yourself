#pragma once
#include <string>
#include <iostream>
class PeerDetails
{
public:
	PeerDetails();
	PeerDetails(std::string ip, std::string width, std::string height);
	std::string getIp();
	std::string getWidth();
	std::string getHeight();
private:
	std::string _ip;
	std::string _width;
	std::string _height;
};