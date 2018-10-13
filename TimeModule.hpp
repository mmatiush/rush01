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
	~TimeModule( void );

	TimeModule &	operator=( TimeModule const & rhs );

	void			parse(std::string & strToParce);

	std::string &	getTime();
	std::string &	getdate();

private:

	std::string		time;
	std::string		date;

};

#endif
