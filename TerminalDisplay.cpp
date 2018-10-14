#include "TerminalDisplay.hpp"

// Constructors and destructors

TerminalDisplay::TerminalDisplay( void ) {

	this->mTime = TimeModule();
	this->mNames = HostUserNames();
	this->mOSInfo = OSInfo();
	this->mNetwork = Network();
	this->mCPU = CPU();
	this->mRAM = RAM();

}

TerminalDisplay::TerminalDisplay( TerminalDisplay const & src ) {

	*this = src;
	return ;

}

TerminalDisplay::~TerminalDisplay( void ) {

	return ;

}

// Operators overload

TerminalDisplay &		TerminalDisplay::operator=( TerminalDisplay const & rhs ) {

	if (this == &rhs)
		return (*this);

	this->mTime = rhs.mTime;
	this->mNames = rhs.mNames;
	this->mOSInfo = rhs.mOSInfo;
	this->mNetwork = rhs.mNetwork;
	this->mCPU = rhs.mCPU;
	this->mRAM = rhs.mRAM;

	return (*this);

}

// Methods

void		TerminalDisplay::updateMonitors( void ) {
	
	char buffer[1000];
	std::string s = "";
	FILE* pipe = popen("top", "r");
	if (!pipe)
		throw std::runtime_error("popen() failed!");

	for (int i = 0; i < 10; i++)
		if (fgets(buffer, 1000, pipe) != NULL)
			s += buffer;
	pclose(pipe);

	mTime.parse(s);
	mNames.parse(s);
	mOSInfo.parse(s);
	mNetwork.parse(s);
	mCPU.parse(s);
	mRAM.parse(s);

}

void 		TerminalDisplay::run( void ) {

	initscr();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	start_color();
    init_pair(TXT_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(TXT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	
	while (-42) {
	
		erase();
	
		displayFrame();
		displayHeader();
		displayTime();

		refresh();
		usleep (100000);

	}

	endwin();

}

void		TerminalDisplay::displayFrame( void ) {


	attron(COLOR_PAIR(TXT_GREEN));
	for (int i = 0; i < MAX_X; ++i) {
		mvprintw(MAX_Y, i, "-");
		mvprintw(MIN_Y, i, "-");
	}
	for (int i = 0; i < MAX_Y; ++i) {
		mvprintw(i, MAX_X, "|");
		mvprintw(i, MIN_X, "|");
	}
	mvprintw(MAX_Y,MAX_X, " ");
	mvprintw(MIN_Y,MIN_X, " ");
	mvprintw(MIN_Y, MAX_X, " ");
	mvprintw(MAX_Y, MIN_X, " ");

	attroff(COLOR_PAIR(TXT_GREEN));

}


void	TerminalDisplay::displayHeader( void ) {
	
	std::string str = "System Monitor";

	mvprintw(MIN_Y, (MAX_X - str.size()) / 2, "%s", str.c_str());

}

void	TerminalDisplay::displayTime( void ) {
	
	std::string t = mTime.getTime();
	std::string d = mTime.getDate();

	mvprintw(MIN_Y + 2, MIN_X + 2, d.c_str());
	mvprintw(MIN_Y + 2, MAX_X + 2 - d.size(), d.c_str());

}

void	TerminalDisplay::displayHostUserName( void ) {

	return ;
}

void	TerminalDisplay::displayNetwork( void ) {

	return ;
}

void	TerminalDisplay::displayCPU( void ) {

	return ;
}

void	TerminalDisplay::displayRAM( void ) {

	return ;
}

void	TerminalDisplay::displayOSinfo( void ) {

	return ;
}


