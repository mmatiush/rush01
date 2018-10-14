#include "CPU.hpp"

CPU::CPU() {
	char buffer[BUFFERLEN];
	size_t bufferlen = BUFFERLEN;

	sysctlbyname("machdep.cpu.brand_string",&buffer,&bufferlen,NULL,0);
	this->_cpuBrand = static_cast<std::string>(buffer);
}

CPU::~CPU() {}

CPU::CPU(CPU const & other)
{
	*this = other;
}

CPU & CPU::operator=(CPU const & other)
{
	if (this != &other)
	{
		this->_cpuBrand = other._cpuBrand;
		this->_avg1 = other._avg1;
		this->_avg5 = other._avg5;
		this->_avg15 = other._avg15;
		this->_usageUser = other._usageUser;
		this->_usageSys = other._usageSys;
		this->_usageIdle = other._usageIdle;
	}

	return (*this);
}

void CPU::parse(std::string & strToParce)
{
	size_t	pos = 0;
	std::string result;

	// Load avg
	pos = strToParce.find("Load Avg:", 0);
	result = strToParce.substr(pos + 10, (strToParce.find("\n", pos)));

	pos = result.find(",", 0);
	this->_avg1 = result.substr(0, pos);

	result = result.substr(this->_avg1.length() + 2);
	pos = result.find(",", 0);
	this->_avg5 = result.substr(0, pos);

	result = result.substr(this->_avg5.length() + 2);
	pos = result.find("\n", 0);
	this->_avg15 = result.substr(0, pos);


	// CPU Usage
	pos = strToParce.find("CPU usage:", 0);
	result = strToParce.substr(pos + 11, strToParce.find("\n", pos) - pos - 11);
	this->_usageUser = result.substr(0, result.find(" user", 0) - 1);

	result = result.substr(this->_usageUser.length() + 8);
	pos = result.find(" s", 0);
	this->_usageSys = result.substr(0, pos - 1);

	result = result.substr(this->_usageSys.length() + 7);
	pos = result.find(" i", 0);
	this->_usageIdle = result.substr(0, pos - 1);

}


std::string CPU::getCpuBrand() const{
	return this->_cpuBrand;
}

std::string CPU::getAvg1() const{
	return this->_avg1;
}

std::string CPU::getAvg5() const{
	return this->_avg5;
}

std::string CPU::getAvg15() const{
	return this->_avg15;
}

std::string CPU::getUsageUser() const{
	return this->_usageUser;
}

std::string CPU::getUsageSys() const{
	return this->_usageSys;
}

std::string CPU::getUsageIdle() const{
	return this->_usageIdle;
}
