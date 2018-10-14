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
	int 	c;

	initscr();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	graph = newwin(3, 22, 35, 10);
	nodelay(stdscr, true);
    init_pair(TXT_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(TXT_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(TXT_RED, COLOR_RED, COLOR_BLACK);
	
	while (-42) {
	
		erase();
		wclear(graph);
		updateMonitors();
		displayFrame();
		displayHeader();
		displayTime();
		displayHostUserName();
		displayOSinfo();
		displayNetwork();
		displayCPU();
		displayRAM();
		displayGraphUserCPU();

		refresh();
		wrefresh(graph);
		c = wgetch(stdscr);
		if (c == 'q') {
			break ;
		}
		usleep (10000);

	}
	endwin();
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

	mvprintw(14, COL1, "Packets In:");
	mvprintw(15, COL1, "Packets Out:");

	mvprintw(14, COL2, pcaketsIn.c_str());
	mvprintw(15, COL2, pcaketsOut.c_str());

}

void	TerminalDisplay::displayCPU( void ) {

	attron(A_REVERSE);
	std::string title = "CPU";
	mvprintw(17, mid(title.size()), title.c_str());
	attroff(A_REVERSE);

	std::string brand = mCPU.getCpuBrand();
	std::string avg1 = mCPU.getAvg1();
	std::string avg5 = mCPU.getAvg5();
	std::string avg15 = mCPU.getAvg15();
	std::string usageUser = mCPU.getUsageUser();
	std::string usageSyste = mCPU.getUsageSys();
	std::string usageIdle = mCPU.getUsageIdle();

	mvprintw(19, COL1, "CPU Brand");
	mvprintw(20, COL1, "Load Average:");
	mvprintw(21, COL1, "Usage");
	mvprintw(22, COL1 + 4, "user:");
	mvprintw(23, COL1 + 4, "system:");
	mvprintw(24, COL1 + 4, "idle:");

	mvprintw(19, COL2, brand.c_str());
	mvprintw(20, COL2, "%s %s %s", avg1.c_str(), avg5.c_str(), avg15.c_str());
	mvprintw(22, COL2, usageUser.c_str());
	mvprintw(23, COL2, usageSyste.c_str());
	mvprintw(24, COL2, usageIdle.c_str());



}

void	TerminalDisplay::displayRAM( void ) {

	attron(A_REVERSE);
	std::string title = "RAM";
	mvprintw(26, mid(title.size()), title.c_str());
	attroff(A_REVERSE);

	std::string physMem = mRAM.getPhysMem();
	std::string wiredMem = mRAM.getWired();
	std::string unusedMem = mRAM.getUnused();

	mvprintw(28, COL1, "Phys Mem:");
	mvprintw(29, COL1, "Wired:");
	mvprintw(30, COL1, "Unused:");

	mvprintw(28, COL2, physMem.c_str());
	mvprintw(29, COL2, wiredMem.c_str());
	mvprintw(30, COL2, unusedMem.c_str());

}

void	TerminalDisplay::displayGraphUserCPU( void ) {

	mvprintw(34, 11, "System CPU Usage");
	box(graph, 0, 0);

	std::string usage_str = mCPU.getUsageSys();
	float		usage_f = atof(usage_str.c_str());
	int			usage = static_cast<int>(usage_f);

	int i = 0;
	int sym = 1;
	while (i < usage) {
		if (i <= 30) {
			wattron(graph, COLOR_PAIR(TXT_GREEN));
			mvwprintw(graph, 1, sym, "|");
			wattroff(graph, COLOR_PAIR(TXT_GREEN));
		}
		else if (i <= 60) {
			wattron(graph, COLOR_PAIR(TXT_YELLOW));
			mvwprintw(graph, 1, sym, "|");
			wattroff(graph, COLOR_PAIR(TXT_YELLOW));
		}
		else {
			wattron(graph, COLOR_PAIR(TXT_RED));
			mvwprintw(graph, 1, sym, "|");
			wattroff(graph, COLOR_PAIR(TXT_RED));
		}
		sym++;
		i += 5;
	}

}
