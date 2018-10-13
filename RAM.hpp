#ifndef RAM_HPP
# define RAM_HPP

# include <string>
# include "IMonitorModule.hpp"
# include <sstream>

class RAM : public IMonitorModule
{

private:

	std::string _physMem;
	std::string _wired;
	std::string _unused;

public:

	std::string getPhysMem() const;
	std::string getWired() const;
	std::string getUnused() const;

	RAM();
	~RAM();
	RAM(RAM const & other);
	RAM & operator=(RAM const & other);

	void parse(std::string & strToParce);

};

#endif
