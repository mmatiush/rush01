#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay()
{
	window = new sf::RenderWindow;
	window->create(sf::VideoMode(1800, 2000), "ft_gkrellm");
	atext = new sf::Text;
	ttext = new sf::Text;
	MyFont = new sf::Font;

	if (!MyFont->loadFromFile("12394.ttf"))
		std::cout << "Error in openning file" << std::endl;

	this->atext->setFont(*MyFont);
	ttext->setFont(*MyFont);
	ttext->setCharacterSize(40);
	ttext->setFillColor(sf::Color::Blue);
}

SFMLDisplay::~SFMLDisplay()
{ 
	delete window;
	delete atext;
	delete ttext;
	delete MyFont;
}

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

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

	this->_timeModule.parse(str);

// Date Label

	atext->setCharacterSize(25);
	atext->setStyle(sf::Text::Bold);
	atext->setFillColor(sf::Color::White);
	atext->setPosition(10, 10);
	atext->setString("Date:");
	window->draw(*atext);

// date
	result = this->_timeModule.getDate();
	tmpText.setPosition(100,10);
	tmpText.setString(result);
	window->draw(tmpText);

// time
	atext->setPosition(1540, 10);
	atext->setString("Time: ");
	window->draw(*atext);

	result = this->_timeModule.getTime();
	tmpText.setPosition(1650,10);
	tmpText.setString(result);
	window->draw(tmpText);

}



// OS INFO
void	SFMLDisplay::displayOSinfo( std::string &str ) {
	this->_oSInfo.parse(str);

	sf::Text tmpText;
	std::string result;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(795, 50);
	ttext->setString("OS Info");
	window->draw(*ttext);

// atext

	atext->setCharacterSize(30);
	atext->setStyle(sf::Text::Bold);
	atext->setFillColor(sf::Color::Yellow);

// ProductName
	atext->setPosition(500, 120);
	atext->setString("Product name:");
	window->draw(*atext);

	tmpText.setString(this->_oSInfo.getProductName());
	tmpText.setPosition(1000, 120);
	window->draw(tmpText);

// Product version
	atext->setPosition(500, 160);
	atext->setString("Product version:");
	window->draw(*atext);

	tmpText.setString(this->_oSInfo.getProductVersion());
	tmpText.setPosition(1000, 160);
	window->draw(tmpText);

// Kernel version
	atext->setPosition(500, 200);
	atext->setString("Kernel version:");
	window->draw(*atext);
	tmpText.setString(this->_oSInfo.getKernelVersion());
	tmpText.setPosition(1000, 200);
	window->draw(tmpText);

}

void	SFMLDisplay::displayHostUserName( std::string &str ) {
	this->_hostUserNames.parse(str);

	sf::Text tmpText;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(650, 280);
	ttext->setString("Hostname / Username");
	window->draw(*ttext);

// Hostname
	atext->setPosition(500, 350);
	atext->setString("Hostname:");
	window->draw(*atext);

	tmpText.setString(this->_hostUserNames.getHostName());
	tmpText.setPosition(1000, 350);
	window->draw(tmpText);

// Hostname
	atext->setPosition(500, 390);
	atext->setString("Username:");
	window->draw(*atext);

	tmpText.setString(this->_hostUserNames.getUserName());
	tmpText.setPosition(1000, 390);
	window->draw(tmpText);
}

void	SFMLDisplay::displayCPU( std::string &str ) {
	this->_cPU.parse(str);

	sf::Text tmpText;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(830, 470);
	ttext->setString("CPU");
	window->draw(*ttext);

// CPU brand
	atext->setPosition(500, 510);
	atext->setString("CPU Brand:");
	window->draw(*atext);

	tmpText.setString(this->_cPU.getCpuBrand());
	tmpText.setPosition(1000, 510);
	window->draw(tmpText);

// loadavg
	atext->setPosition(500, 550);
	atext->setString("Load average:");
	window->draw(*atext);

	tmpText.setString(this->_cPU.getAvg1());
	tmpText.setPosition(1000, 550);
	window->draw(tmpText);
	tmpText.setString(this->_cPU.getAvg5());
	tmpText.setPosition(1100, 550);
	window->draw(tmpText);
	tmpText.setString(this->_cPU.getAvg15());
	tmpText.setPosition(1200, 550);
	window->draw(tmpText);

// usage
	atext->setPosition(500, 590);
	atext->setString("USAGE:");
	window->draw(*atext);

	atext->setPosition(550, 630);
	atext->setString("user:");
	window->draw(*atext);

	atext->setPosition(550, 670);
	atext->setString("system:");
	window->draw(*atext);

	atext->setPosition(550, 710);
	atext->setString("idle:");
	window->draw(*atext);

// user
	tmpText.setString(this->_cPU.getUsageUser() + "%");
	tmpText.setPosition(1000, 630);
	window->draw(tmpText);

// sys
	tmpText.setString(this->_cPU.getUsageSys() + "%");
	tmpText.setPosition(1000, 670);
	window->draw(tmpText);

// idle
	tmpText.setString(this->_cPU.getUsageIdle() + "%");
	tmpText.setPosition(1000, 710);
	window->draw(tmpText);

}

void	SFMLDisplay::displayRAM( std::string &str ) {
	this->_rAM.parse(str);

	sf::Text tmpText;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(830, 790);
	ttext->setString("RAM");
	window->draw(*ttext);

// atext
	atext->setPosition(500, 830);
	atext->setString("PhysMem:");
	window->draw(*atext);

	atext->setPosition(500, 870);
	atext->setString("Wired:");
	window->draw(*atext);

	atext->setPosition(500, 910);
	atext->setString("Unused:");
	window->draw(*atext);

// PhysMem
	tmpText.setString(this->_rAM.getPhysMem());
	tmpText.setPosition(1000, 830);
	window->draw(tmpText);

	tmpText.setString(this->_rAM.getWired());
	tmpText.setPosition(1000, 870);
	window->draw(tmpText);

	tmpText.setString(this->_rAM.getUnused());
	tmpText.setPosition(1000, 910);
	window->draw(tmpText);

}

void	SFMLDisplay::displayNetwork( std::string &str ) {
	this->_network.parse(str);

	sf::Text tmpText;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(800, 990);
	ttext->setString("Network");
	window->draw(*ttext);

// atext
	atext->setPosition(500, 1030);
	atext->setString("Packets In:");
	window->draw(*atext);

	atext->setPosition(500, 1070);
	atext->setString("Packets Out:");
	window->draw(*atext);

// in
	tmpText.setString(this->_network.getPacketsIn());
	tmpText.setPosition(1000, 1030);
	window->draw(tmpText);

// out
	tmpText.setString(this->_network.getPacketsOut());
	tmpText.setPosition(1000, 1070);
	window->draw(tmpText);

}



void	SFMLDisplay::display( void ) {
	std::string StrToParse;

	while (window->isOpen())
	{
		StrToParse = ft_exec("top");
		window->clear();

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		displayTime( StrToParse );
		displayOSinfo( StrToParse );
		displayHostUserName( StrToParse );
		displayCPU( StrToParse );
		displayRAM( StrToParse );
		displayNetwork( StrToParse );

		window->display();
	}

}

std::string	SFMLDisplay::ft_exec(const char *cmd)
{

	char buffer[1000];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		throw std::runtime_error("popen() failed!");

	for (int i = 0; i < 10; i++)
		if (fgets(buffer, 1000, pipe) != NULL)
			result += buffer;
	pclose(pipe);

	return result;
}