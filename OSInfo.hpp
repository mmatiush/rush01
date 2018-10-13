#ifndef OSINFO_HPP
# define OSINFO_HPP
# include <iostream>
# include <string>
# include "IMonitorModule.hpp"

class OSInfo : public IMonitorModule
{

public:

	OSInfo();
	~OSInfo();
	OSInfo(OSInfo const & other);
	OSInfo & operator=(OSInfo const & other);

	void parce(std::string & strToParce, std::map<std::string, std::string> & map);

};

#endif
