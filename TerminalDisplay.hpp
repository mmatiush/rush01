#ifndef TERMINALDISPLAY_HPP
# define TERMINALDISPLAY_HPP
# include <iostream>
#include "IMonitorDisplay.hpp"
class TerminalDisplay : IMonitorDisplay {

public:

	TerminalDisplay( void );
	TerminalDisplay( TerminalDisplay const & src );
	virtual ~TerminalDisplay( void );

	TerminalDisplay &	operator=( TerminalDisplay const & rhs );

	void run( void );

private:


};

#endif
