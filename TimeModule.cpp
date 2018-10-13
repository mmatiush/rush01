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

std::string &		TimeModule::getTime( void ) {
	return (this->_time);
}

std::string &		TimeModule::getDate( void ) {
	return (this->_date);
}

// Operators overload

TimeModule &		TimeModule::operator=( TimeModule const & rhs ) {

	if (this == &rhs)
		return (*this);
	this->_time = rhs._time;
	this->_date = rhs._date;

	return (*this);

}

// Methods

void				TimeModule::parse( std::string & strToParce ) {

	size_t start;
	size_t end;
	size_t space;

	start = strToParce.find("\n", 0);
	end = strToParce.find("\n", start + 1);
	std::string res = strToParce.substr(start + 1, end - start -1);


	space = res.find(" ", 0);
	this->_date = res.substr(0, space);
	this->_time = res.substr(space + 1, res.size() - space - 1);

}

