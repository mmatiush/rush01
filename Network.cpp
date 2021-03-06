#include "Network.hpp"

Network::Network()
{

}

Network::~Network()
{

}

Network::Network(Network const & other)
{
	*this = other;
}

Network & Network::operator=(Network const & other)
{
	if (this != &other)
	{
		this->_packetsIn = other._packetsIn;
		this->_packetsOut = other._packetsOut;
	}

	return (*this);
}

std::string Network::getPacketsIn() const{
	return this->_packetsIn;
}

std::string Network::getPacketsOut() const{
	return this->_packetsOut;
}

void Network::parse(std::string & strToParce) {
	
	size_t	pos = 0;
	std::string result;

	pos = strToParce.find("packets: ", 0);
	result = strToParce.substr(pos + 9, (strToParce.find("\n", pos)));

	pos = result.find(" i", 0);
	this->_packetsIn = result.substr(0, pos);

	result = result.substr(this->_packetsIn.length() + 5);
	this->_packetsOut = result.substr(0, result.find(" o"));

}
