#ifndef HOSTUSERNAMES_HPP
# define HOSTUSERNAMES_HPP
# include <iostream>
# include <unistd.h>
# include "IMonitorModule.hpp"

class HostUserNames : public IMonitorModule {

public:

	HostUserNames( void );
	HostUserNames( HostUserNames const & src );
	virtual ~HostUserNames( void );

	HostUserNames &	operator=( HostUserNames const & rhs );

	void		parse(std::string & strToParce);

	char *		getHostName( void );
	char *		getUserName( void );

private:

	char		_hostName[_POSIX_HOST_NAME_MAX + 1];
	char		_userName[_POSIX_LOGIN_NAME_MAX + 1];

};


#endif
