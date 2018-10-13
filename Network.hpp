#ifndef NETWORK_HPP
# define NETWORK_HPP
# include "IMonitorModule.hpp"
# include <string>

class Network : public IMonitorModule
{

private:

	std::string _packetsIn;
	std::string _packetsOut;

public:

	std::string getPacketsIn() const;
	std::string getPacketsOut() const;

	Network();
	~Network();
	Network(Network const & other);
	Network & operator=(Network const & other);

	void parse(std::string & strToParce);

};

#endif
