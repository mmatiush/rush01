#include "RAM.hpp"

RAM::RAM() {}

RAM::~RAM() {}

RAM::RAM(RAM const & other)
{
	*this = other;
}

RAM & RAM::operator=(RAM const & other)
{
	if (this != &other)
	{
		this->_physMem = other._physMem;
		this->_wired = other._wired;
		this->_unused = other._unused;
	}

		return (*this);
}

void RAM::parse(std::string & strToParce)
{
	size_t	pos = 0;
	std::string result;

	pos = strToParce.find("PhysMem: ", 0);
	result = strToParce.substr(pos, (strToParce.find("\n", pos)) - pos);

	pos = result.find(" used", 0);
	this->_physMem = result.substr(10, pos);

	pos = result.find(" wired", 0);
	this->_wired = result.substr((result.find("(", 0) + 1), pos - 1);

	pos = result.find(" unused", 0);
	this->_unused = result.substr((result.find(",", 0) + 1), pos - 1);

}

std::string RAM::getPhysMem() const {
	return this->_physMem;
}

std::string RAM::getWired() const {
	return this->_wired;
}

std::string RAM::getUnused() const {
	return this->_unused;
}
