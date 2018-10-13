#ifndef HOSTNAMEUSERNAME_HPP
# define HOSTNAMEUSERNAME_HPP

# include "IMonitorModule.hpp"
# include <string>

class HostnameUsername : public IMonitorModule
{

private:

	std::string _hostname;
	std::string _username;

public:

	std::string getHostname() const;
	std::string getUsername() const;


	HostnameUsername();
	~HostnameUsername();
	HostnameUsername(HostnameUsername const & other);
	HostnameUsername & operator=(HostnameUsername const & other);

};

#endif
