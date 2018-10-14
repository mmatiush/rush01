#include "MLXDisplay.hpp"

MLXDisplay::MLXDisplay()
{
	this->_modules = std::vector<IMonitorModule *>(6);
	this->_modules[0] = new TimeModule;
	this->_modules[1] = new OSInfo;
	this->_modules[2] = new HostUserNames;
	this->_modules[3] = new CPU;
	this->_modules[4] = new RAM;
	this->_modules[5] = new Network;
}

MLXDisplay::~MLXDisplay()
{
	std::vector<IMonitorModule *>::iterator it = _modules.begin();

	for (; it != _modules.end(); it++)
		delete *it;
}

MLXDisplay::MLXDisplay(MLXDisplay const & other)
{
	*this = other;
}

MLXDisplay & MLXDisplay::operator=(MLXDisplay const & other)
{
	if (this != &other) {
		std::vector<IMonitorModule *>::iterator it = this->_modules.begin();
		for (; it != this->_modules.end(); it++)
			delete *it;

		this->_modules = std::vector<IMonitorModule *>(6);
		this->_modules[0] = new TimeModule;
		this->_modules[1] = new OSInfo;
		this->_modules[2] = new HostUserNames;
		this->_modules[3] = new CPU;
		this->_modules[4] = new RAM;
		this->_modules[5] = new Network;
	}

	return (*this);
}

std::vector<IMonitorModule *> MLXDisplay::getModules() const
{
	return this->_modules;
}

void	displayHostUserName( void ) {
}

void	displayNetwork( void ) {
}

void	displayCPU( void ) {
}

void	displayRAM( void ) {
}

void	displayOSinfo( void ) {
}

void	displayTime( void ) {
}
