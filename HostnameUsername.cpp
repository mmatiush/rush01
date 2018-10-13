#include "HostnameUsername.hpp"

HostnameUsername::HostnameUsername()
{
	
}

HostnameUsername::~HostnameUsername()
{

}

HostnameUsername::HostnameUsername(HostnameUsername const & other)
{
	*this = other;
}

HostnameUsername & HostnameUsername::operator=(HostnameUsername const & other)
{
	
	return (*this);
}

std::string HostnameUsername::getHostname() const {
	return this->_hostname;
}

std::string HostnameUsername::getUsername() const {
	return this->_username;
}
