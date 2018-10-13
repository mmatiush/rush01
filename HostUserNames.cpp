#include "HostUserNames.hpp"

// Constructors and destructors

HostUserNames::HostUserNames( void ) {

	return ;

}

HostUserNames::HostUserNames( HostUserNames const & src ) {

	*this = src;
	return ;

}

HostUserNames::~HostUserNames( void ) {

	return ;

}

// Getters and setters

char *			HostUserNames::getHostName( void ) {
	return (this->_hostName);
}
char *			HostUserNames::getUserName( void ) {
	return (this->_userName);
}

// Operators overload

HostUserNames &		HostUserNames::operator=( HostUserNames const & rhs ) {

	if (this == &rhs)
		return (*this);
	strcpy(this->_hostName, rhs._hostName);
	strcpy(this->_userName, rhs._userName);

	return (*this);

}

// Methods

void			HostUserNames::parse(std::string & strToParce) {

	if (strToParce.size()) {
		gethostname(_hostName, _POSIX_HOST_NAME_MAX);
		getlogin_r(_userName, _POSIX_LOGIN_NAME_MAX);
	}
}

