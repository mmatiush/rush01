#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay() 
{
	TimeModule		_timeModule;
	OSInfo			_oSInfo;
	HostUserNames	_hostUserNames;
	CPU				_cPU;
	RAM				_rAM;
	Network			_network;

	window.create(sf::VideoMode(1800, 2000), "ft_gkrellm");

	sf::Text	atext;
	sf::Text	ttext;
	sf::Font	MyFont;

	if (!this->MyFont.loadFromFile("12394.ttf"))
		std::cout << "Error in openning file" << std::endl;

	this->atext.setFont(MyFont);
	this->ttext.setFont(MyFont);
	this->ttext.setCharacterSize(40);
	this->ttext.setFillColor(sf::Color::Blue);
}

SFMLDisplay::~SFMLDisplay()
{ }

SFMLDisplay::SFMLDisplay(SFMLDisplay const & other)
{
	*this = other;
}

SFMLDisplay & SFMLDisplay::operator=(SFMLDisplay const & other)
{
	if (this != &other)
		;
	return (*this);
}

void	SFMLDisplay::displayHostUserName( void ) {
}

void	SFMLDisplay::displayNetwork( void ) {}

void	SFMLDisplay::displayCPU( void ) {}

void	SFMLDisplay::displayRAM( void ) {}

void	SFMLDisplay::displayOSinfo( void ) {}

void	SFMLDisplay::displayTime( void ) {}


// TIME
void	SFMLDisplay::displayTime( std::string &str ) {
	sf::Text tmpText;
	std::string result;

	tmpText.setFont(MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

	this->_timeModule.parse(str);

// Date Label

	atext.setCharacterSize(25);
	atext.setStyle(sf::Text::Bold);
	atext.setFillColor(sf::Color::White);
	atext.setPosition(10, 10);
	atext.setString("Date:");
	window.draw(atext);

// date
	result = this->_timeModule.getDate();
	tmpText.setPosition(100,10);
	tmpText.setString(result);
	window.draw(tmpText);

// time
	atext.setPosition(1540, 10);
	atext.setString("Time: ");
	window.draw(atext);

	result = this->_timeModule.getTime();
	tmpText.setPosition(1650,10);
	tmpText.setString(result);
	window.draw(tmpText);

}



// OS INFO
// void	SFMLDisplay::displayOSinfo( std::string &str ) {
// 	this->_oSInfo.parse(str);

// 	sf::Text tmpText;
// 	std::string result;

// 	tmpText.setFont(MyFont);
// 	tmpText.setCharacterSize(25);
// 	tmpText.setStyle(sf::Text::Bold);
// 	tmpText.setFillColor(sf::Color::White);

// // Title
// 	// ttext.setPosition(795, 50);
// 	// ttext.setString("OS Info");
// 	// window.draw(ttext);

// // atext

// 	atext.setCharacterSize(30);
// 	atext.setStyle(sf::Text::Bold);
// 	atext.setFillColor(sf::Color::Yellow);
// 	atext.setPosition(10, 10);
// 	atext.setString("Product name:");
// 	window.draw(atext);

// // ProductName
// 	tmpText.setString(this->_oSInfo.getProductName());
// 	tmpText.setPosition(900, 120);
// 	window.draw(tmpText);

// 	tmpText.setString(this->_oSInfo.getProductVersion());
// 	tmpText.setPosition(900, 160);
// 	window.draw(tmpText);
	
// 	tmpText.setString(this->_oSInfo.getKernelVersion());
// 	tmpText.setPosition(900, 200);
// 	window.draw(tmpText);

// }

// void	SFMLDisplay::displayHostUserName( std::string &str ) {
// 	this->_hostUserNames.parse(str);
// }

// void	SFMLDisplay::displayCPU( std::string &str ) {
// 	this->_cPU.parse(str);
// }

// void	SFMLDisplay::displayRAM( std::string &str ) {
// 	this->_rAM.parse(str);
// }

// void	SFMLDisplay::displayNetwork( sf::RenderWindow & window, sf::Text & atext, std::string &str ) {
// 	this->_network.parse(str);
// }



void	SFMLDisplay::display( void ) {
	std::string StrToParse;

	while (window.isOpen())
	{
		StrToParse = exec("top");
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		displayTime( StrToParse );
		// displayOSinfo( StrToParse );
		// displayHostUserName( StrToParse );
		// displayCPU( StrToParse );
		// displayRAM( StrToParse );
		// displayNetwork( StrToParse );

		window.display();
	}

}
