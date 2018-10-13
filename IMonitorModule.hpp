#ifndef IMONITOR_MODULE_HPP
# define IMONITOR_MODULE_HPP

# include <ncurses.h>
# include <map>

class IMonitorModule
{

public:

	virtual ~IMonitorModule() {}
	virtual void parse(std::string & strToParce, std::map<std::string, std::string> & map);

};

#endif
