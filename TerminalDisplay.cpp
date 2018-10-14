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
		updateMonitors();

		displayFrame();
		displayHeader();
		displayTime();
		displayHostUserName();
		displayOSinfo();
		displayNetwork();

		refresh();
		usleep (10000);

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
	
	attron(A_REVERSE);

	std::string str = "System Monitor";
	mvprintw(MIN_Y, (MAX_X - str.size()) / 2, "%s", str.c_str());
	
	attroff(A_REVERSE);

}

void	TerminalDisplay::displayTime( void ) {

	std::string t = mTime.getTime();
	std::string d = mTime.getDate();

	mvprintw(MIN_Y + 1, MIN_X + 2, d.c_str());
	mvprintw(MIN_Y + 1, MAX_X - 1 - t.size(), t.c_str());

}

void	TerminalDisplay::displayHostUserName( void ) {

	mvprintw(3, COL1, "Userame:");
	mvprintw(4, COL1, "Hostname:");

	std::string user = mNames.getUserName();
	std::string host = mNames.getHostName();

	mvprintw(3, COL2, user.c_str());
	mvprintw(4, COL2, host.c_str());

}


void	TerminalDisplay::displayOSinfo( void ) {

	attron(A_REVERSE);
	std::string title = "OS Info";
	mvprintw(6, mid(title.size()), title.c_str());
	attroff(A_REVERSE);

	std::string name = mOSInfo.getProductName();
	std::string prodVersion = mOSInfo.getProductVersion();
	std::string kernelVersion = mOSInfo.getKernelVersion();


	mvprintw(8, COL1, "Product Name:");
	mvprintw(9, COL1, "Product Version:");
	mvprintw(10, COL1, "KernelVersion:");

	mvprintw(8, COL2, name.c_str());
	mvprintw(9, COL2, prodVersion.c_str());
	mvprintw(10, COL2, kernelVersion.c_str());

}

void	TerminalDisplay::displayNetwork( void ) {

	attron(A_REVERSE);
	std::string title = "Network";
	mvprintw(12, mid(title.size()), title.c_str());
	attroff(A_REVERSE);

	std::string pcaketsIn = mNetwork.getPacketsIn();
	std::string pcaketsOut = mNetwork.getPacketsOut();

	mvprintw(8, COL1, "pa:");
	mvprintw(9, COL1, "Product Version:");
	mvprintw(10, COL1, "KernelVersion:");

	// mvprintw(8, COL2, name.c_str());
	// mvprintw(9, COL2, prodVersion.c_str());
	// mvprintw(10, COL2, kernelVersion.c_str());

}

void	TerminalDisplay::displayCPU( void ) {

	return ;
}

void	TerminalDisplay::displayRAM( void ) {

	return ;
}



