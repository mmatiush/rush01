#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{

public:

	virtual ~IMonitorDisplay() {}

	virtual void	displayHostUserName( void ) = 0;
	virtual void	displayNetwork( void ) = 0;
	virtual void	displayCPU( void ) = 0;
	virtual void	displayRAM( void ) = 0;
	virtual void	displayOSinfo( void ) = 0;
	virtual void	displayTime( void ) = 0;

};

#endif
