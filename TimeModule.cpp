#include "TimeModule.hpp"

// Constructors and destructors

TimeModule::TimeModule( void ) {

	return ;

}

TimeModule::TimeModule( TimeModule const & src ) {

	*this = src;
	return ;

}

TimeModule::~TimeModule( void ) {

	return ;

}

// Getters and setters


// Operators overload

TimeModule &		TimeModule::operator=( TimeModule const & rhs ) {

	if (this == &rhs)
		return (*this);
	this->time = rhs.time;
	this->date = rhs.date;

	return (*this);

}

// Methods

void				TimeModule::parse( std::string & strToParce ) {

	size_t start;
	size_t end;

	start = strToParce.find("\n", 0);
	end = strToParce.find("\n", start + 1);
	std::string res = strToParce.substr(start, end);

	std::cout << " RES: " << res << std::endl;

	// std::getline(strToParce, str);
	// std::getline(strToParce, str);

}

