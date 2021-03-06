#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

# include <sys/types.h>
# include <sys/sysctl.h>
# include <string>

#define BUFFERLEN 512

class IMonitorModule
{

public:

	virtual ~IMonitorModule() {}
	virtual void parse(std::string & strToParce) = 0;

};

#endif
