#ifndef TERMINALDISPLAY_HPP
# define TERMINALDISPLAY_HPP
# include <iostream>
# include "IMonitorDisplay.hpp"

# include <ncurses.h>
# include <unistd.h> 

# define MIN_X	0
# define MIN_Y	0
# define MAX_X	100
# define MAX_Y	30

# define COL1	3
# define COL2	50


# define TXT_GREEN 1
# define TXT_YELLOW 2

class TerminalDisplay : public IMonitorDisplay {

public:

	TerminalDisplay( void );
	TerminalDisplay( TerminalDisplay const & src );
	virtual ~TerminalDisplay( void );

	TerminalDisplay &	operator=( TerminalDisplay const & rhs );

// Methods

	void		updateMonitors( void );

	void		run( void );
	void		displayHeader( void );
	void		displayFrame( void );
	void		displayTime( void );
	void		displayHostUserName( void );
	void		displayNetwork( void );
	void		displayCPU( void );
	void		displayRAM( void );
	void		displayOSinfo( void );

private:

	TimeModule			mTime;
	HostUserNames		mNames;
	OSInfo				mOSInfo;
	Network 			mNetwork;
	CPU 				mCPU;
	RAM 				mRAM;

};

#endif
