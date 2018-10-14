#ifndef SFMLDISPLAY_HPP
# define SFMLDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <SFML/Graphics.hpp>
# include <SFML/Graphics/Font.hpp>
# include <SFML/Graphics/Texture.hpp>
# include <SFML/System/String.hpp>
# include <SFML/System/Time.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
# include <SFML/Graphics/RenderTarget.hpp>
# include <vector>

class SFMLDisplay : public IMonitorDisplay
{

private:

	sf::RenderWindow	*window;
	sf::Text			*atext;
	sf::Text			*ttext;
	sf::Font			*MyFont;
	sf::Texture			*texture1;
	sf::Texture			*texture2;
	sf::Sprite			*sprite1;
	sf::Sprite			*sprite2;

	TimeModule		_timeModule;
	OSInfo			_oSInfo;
	HostUserNames	_hostUserNames;
	CPU				_cPU;
	RAM				_rAM;
	Network			_network;

	std::vector<sf::RectangleShape *> _rect;

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
	void	displayCats( void );
	void	displayLines( void );
	void	displayHist( void );

	void	displayTime( std::string &str );
	void	displayOSinfo( std::string &str );
	void	displayHostUserName( std::string &str );
	void	displayCPU( std::string &str );
	void	displayRAM( std::string &str );
	void	displayNetwork( std::string &str );

	void		display();
	std::string	ft_exec(const char *cmd);

};

#endif
