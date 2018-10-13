#include "OSInfo.hpp"

OSInfo::OSInfo()
{
	char buffer[BUFFERLEN];
	size_t bufferlen = BUFFERLEN;

	this->_productName = "Mac OS X";
	sysctlbyname("kern.osversion",&buffer,&bufferlen,NULL,0);
	this->_buildVersion = static_cast<std::string>(buffer);

	sysctlbyname("kern.osrelease",&buffer,&bufferlen,NULL,0);
	this->_productVersion = static_cast<std::string>(buffer);

	sysctlbyname("kern.version",&buffer,&bufferlen,NULL,0);
	this->_kernelVersion = buffer;

}

OSInfo::~OSInfo() {}

OSInfo::OSInfo(OSInfo const & other)
{
	*this = other;
}

OSInfo & OSInfo::operator=(OSInfo const & other)
{
	if (this != &other)
	{
		this->_buildVersion = other._buildVersion;
		this->_productName = other._productName;
		this->_productVersion = other._productVersion;
		this->_kernelVersion = other._kernelVersion;
	}

	return (*this);
}

std::string OSInfo::getProductName() const
{
	return this->_productName;
}

std::string OSInfo::getBuildVersion() const
{
	return this->_buildVersion;
}

std::string OSInfo::getProductVersion() const
{
	return this->_productVersion;
}

std::string OSInfo::getKernelVersion() const
{
	return this->_kernelVersion;
}