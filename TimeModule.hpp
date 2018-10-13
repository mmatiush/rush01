#ifndef TIMEMODULE_HPP
# define TIMEMODULE_HPP
# include "IMonitorModule.hpp"
# include <iostream>
# include <string>
# include <sstream>

class TimeModule : public IMonitorModule {

public:

	TimeModule( void );
	TimeModule( TimeModule const & src );
	virtual ~TimeModule( void );

	TimeModule &	operator=( TimeModule const & rhs );

	void			parse(std::string & strToParce);

	std::string &	getTime();
	std::string &	getDate();

private:

	std::string		_time;
	std::string		_date;

};

#endif
