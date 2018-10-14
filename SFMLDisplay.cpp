#include "SFMLDisplay.hpp"

SFMLDisplay::SFMLDisplay() : _rect(std::vector<sf::RectangleShape *>(10))
{
	window = new sf::RenderWindow;
	window->create(sf::VideoMode(1800, 1800), "ft_gkrellm");
	atext = new sf::Text;
	ttext = new sf::Text;
	MyFont = new sf::Font;
	texture1 = new sf::Texture;
	sprite1 = new sf::Sprite;
	texture2 = new sf::Texture;
	sprite2 = new sf::Sprite;

	try
	{
		if (!MyFont->loadFromFile("12394.ttf"))
			throw std::string("Error");
		if (!texture1->loadFromFile("cat1.png"))
			throw std::string("Error");
		if (!texture2->loadFromFile("cat2.png"))
			throw std::string("Error");
	}
	catch (...)
	{
		std::cout << "Error in construct!" << std::endl;
	}

	this->atext->setFont(*MyFont);
	ttext->setFont(*MyFont);
	ttext->setCharacterSize(40);
	ttext->setFillColor(sf::Color::Blue);

	sprite1->setTexture(*texture1);
	sprite1->setPosition(1300,1200);
	sprite2->setTexture(*texture2);
	sprite2->setPosition(0,1500);

	std::vector<sf::RectangleShape *>::iterator it = _rect.begin();
	for(int x = 0; it != _rect.end(); it++, (x += 11))
	{
		*it = new sf::RectangleShape(sf::Vector2f(10, 1));
		(*it)->setFillColor(sf::Color::Green);
		(*it)->setPosition(400 + x, 1500);
	}
}

SFMLDisplay::~SFMLDisplay()
{ 
	delete window;
	delete atext;
	delete ttext;
	delete MyFont;
	delete texture1;
	delete sprite1;
	delete texture2;
	delete sprite2;

	std::vector<sf::RectangleShape *>::iterator it = _rect.begin();
	for(; it != _rect.end(); it++)
		delete *it;
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


void	SFMLDisplay::displayHist( void )
{
	std::vector<sf::RectangleShape *>::iterator it = --(_rect.end());
	for(; it != _rect.begin(); it--)
	{
		*it->setScale((*(it - 1))->getScale());
		window->draw(*it);
	}
	*it.setScale(sf::Vector2f(10, (std::stod(_cPU.getUsageSys()) * 2)));
	window->draw(*it);
}

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
	atext->setPosition(500, 550);
	atext->setString("CPU Brand:");
	window->draw(*atext);

	tmpText.setString(this->_cPU.getCpuBrand());
	tmpText.setPosition(1000, 550);
	window->draw(tmpText);

// loadavg
	atext->setPosition(500, 590);
	atext->setString("Load average:");
	window->draw(*atext);

	tmpText.setString(this->_cPU.getAvg1());
	tmpText.setPosition(1000, 590);
	window->draw(tmpText);
	tmpText.setString(this->_cPU.getAvg5());
	tmpText.setPosition(1100, 590);
	window->draw(tmpText);
	tmpText.setString(this->_cPU.getAvg15());
	tmpText.setPosition(1200, 590);
	window->draw(tmpText);

// usage
	atext->setPosition(500, 630);
	atext->setString("USAGE:");
	window->draw(*atext);

	atext->setPosition(550, 670);
	atext->setString("user:");
	window->draw(*atext);

	atext->setPosition(550, 710);
	atext->setString("system:");
	window->draw(*atext);

	atext->setPosition(550, 750);
	atext->setString("idle:");
	window->draw(*atext);

// user
	tmpText.setString(this->_cPU.getUsageUser() + "%");
	tmpText.setPosition(1000, 670);
	window->draw(tmpText);

// sys
	tmpText.setString(this->_cPU.getUsageSys() + "%");
	tmpText.setPosition(1000, 710);
	window->draw(tmpText);

// idle
	tmpText.setString(this->_cPU.getUsageIdle() + "%");
	tmpText.setPosition(1000, 750);
	window->draw(tmpText);

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

void	SFMLDisplay::displayRAM( std::string &str ) {
	this->_rAM.parse(str);

	sf::Text tmpText;

	tmpText.setFont(*MyFont);
	tmpText.setCharacterSize(25);
	tmpText.setStyle(sf::Text::Bold);
	tmpText.setFillColor(sf::Color::White);

// Title
	ttext->setPosition(830, 830);
	ttext->setString("RAM");
	window->draw(*ttext);

// atext
	atext->setPosition(500, 910);
	atext->setString("Used:");
	window->draw(*atext);

	atext->setPosition(500, 950);
	atext->setString("Wired:");
	window->draw(*atext);

	atext->setPosition(500, 990);
	atext->setString("Unused:");
	window->draw(*atext);

// PhysMem
	tmpText.setString(this->_rAM.getPhysMem());
	tmpText.setPosition(1000, 910);
	window->draw(tmpText);

	tmpText.setString(this->_rAM.getWired());
	tmpText.setPosition(1000, 950);
	window->draw(tmpText);

	tmpText.setString(this->_rAM.getUnused());
	tmpText.setPosition(1000, 990);
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
	ttext->setPosition(800, 1070);
	ttext->setString("Network");
	window->draw(*ttext);

// atext
	atext->setPosition(500, 1150);
	atext->setString("Packets In:");
	window->draw(*atext);

	atext->setPosition(500, 1190);
	atext->setString("Packets Out:");
	window->draw(*atext);

// in
	tmpText.setString(this->_network.getPacketsIn());
	tmpText.setPosition(1000, 1150);
	window->draw(tmpText);

// out
	tmpText.setString(this->_network.getPacketsOut());
	tmpText.setPosition(1000, 1190);
	window->draw(tmpText);

}

void	SFMLDisplay::displayCats( void )
{
	window->draw(*sprite1);
	window->draw(*sprite2);
}

void	SFMLDisplay::displayLines(void)
{
	sf::VertexArray lines(sf::LinesStrip, 5);

	lines[0].position = sf::Vector2f(10, 45);
	lines[1].position = sf::Vector2f(1790, 45);
	lines[2].position = sf::Vector2f(1790, 1250);
	lines[3].position = sf::Vector2f(10, 1250);
	lines[4].position = sf::Vector2f(10, 45);

	lines[0].color = sf::Color::Green;
	lines[1].color = sf::Color::Blue;
	lines[2].color = sf::Color::Blue;
	lines[3].color = sf::Color::Green;
	lines[4].color = sf::Color::Green;

	window->draw(lines);

	lines = sf::VertexArray(sf::LinesStrip, 2);
	lines[0].position = sf::Vector2f(10, 260);
	lines[1].position = sf::Vector2f(1790, 260);
	lines[0].color = sf::Color::Green;
	lines[1].color = sf::Color::Blue;
	window->draw(lines);

	lines[0].position = sf::Vector2f(10, 450);
	lines[1].position = sf::Vector2f(1790, 450);
	window->draw(lines);

	lines[0].position = sf::Vector2f(10, 810);
	lines[1].position = sf::Vector2f(1790, 810);
	window->draw(lines);

	lines[0].position = sf::Vector2f(10, 1050);
	lines[1].position = sf::Vector2f(1790, 1050);
	window->draw(lines);
}


void	SFMLDisplay::display( void ) {
	std::string StrToParse;
	sf::Time t1 = sf::seconds(1.0f);

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

		displayLines();
		displayCats();
		displayTime( StrToParse );
		displayOSinfo( StrToParse );
		displayHostUserName( StrToParse );
		displayCPU( StrToParse );
		displayRAM( StrToParse );
		displayNetwork( StrToParse );
		displayHist();

		window->display();
		sf::sleep(t1);
	}
}
