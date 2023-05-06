#include "PeerDetails.h"

PeerDetails::PeerDetails()
{
}

PeerDetails::PeerDetails(std::string ip, std::string width, std::string height)
{
	this->_ip = ip;
	this->_width = width;
	this->_height = height;
}

std::string PeerDetails::getIp()
{
	return this->_ip;
}

std::string PeerDetails::getWidth()
{
	return this->_width;
}

std::string PeerDetails::getHeight()
{
	return this->_height;
}
