#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include "OSInfo.hpp"
# include "TimeModule.hpp"
# include "HostUserNames.hpp"
# include "RAM.hpp"
# include "CPU.hpp"
# include "Network.hpp"
# include <vector>
# include <SFML/Graphics.hpp>
# include <SFML/Graphics/Font.hpp>
# include <SFML/System/String.hpp>


class SFMLDisplay : public IMonitorDisplay
{

private:

	sf::RenderWindow	&window;
	sf::Text			&atext;
	sf::Text			&ttext;
	sf::Font			&MyFont;

	TimeModule		_timeModule;
	OSInfo			_oSInfo;
	HostUserNames	_hostUserNames;
	CPU				_cPU;
	RAM				_rAM;
	Network			_network;


public:

	SFMLDisplay();
	~SFMLDisplay();
	SFMLDisplay(SFMLDisplay const & other);
	SFMLDisplay & operator=(SFMLDisplay const & other);

	void	displayTime( void );
	void	displayOSinfo( void );
	void	displayHostUserName( void );
	void	displayCPU( void );
	void	displayRAM( void );
	void	displayNetwork( void );

	void	displayTime( std::string &str );
	// void	displayOSinfo( std::string &str );
	// void	displayHostUserName( std::string &str );
	// void	displayCPU( std::string &str );
	// void	displayRAM( std::string &str );
	// void	displayNetwork( std::string &str );

	void		display();
	std::string	ft_exec();

};

#endif
