#include "TerminalDisplay.hpp"

// Constructors and destructors

TerminalDisplay::TerminalDisplay( void ) {



	return ;

}

TerminalDisplay::TerminalDisplay( TerminalDisplay const & src ) {

	*this = src;
	return ;

}

TerminalDisplay::~TerminalDisplay( void ) {

	return ;

}

// Getters and setters

// Operators overload

TerminalDisplay &		TerminalDisplay::operator=( TerminalDisplay const & rhs ) {

	if (this == &rhs)
		return (*this);
	/*data*/

	return (*this);

}

// Methods

void TerminalDisplay::run( void ) {
	
}
