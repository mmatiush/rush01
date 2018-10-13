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

void				parse( std::string & strToParce ) {
	std::cout << strToParce << std::endl;
}

