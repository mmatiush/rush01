#ifndef OSINFO_HPP
# define OSINFO_HPP

# include <string>
# include "IMonitorModule.hpp"

class OSInfo : public IMonitorModule
{

private:

	std::string _productName;
	std::string _buildVersion;
	std::string _productVersion;

public:

	std::string getProductName() const;
	std::string getBuildVersion() const;
	std::string getProductVersion() const;

	OSInfo();
	~OSInfo();
	OSInfo(OSInfo const & other);
	OSInfo & operator=(OSInfo const & other);

	void parse(std::string & strToParce);

};

#endif
