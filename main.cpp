#include "IMonitorModule.hpp"

int main(void)
{
	initscr();
	noecho();
	cbreak();
	curs_set(0);

	getch();

	endwin();
}
