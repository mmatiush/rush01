#ifndef RAM_HPP
# define RAM_HPP

# include <string>
# include "IMonitorModule.hpp"
# include <sstream>

class Ram : public IMonitorModule
{

private:

	std::string _physMem;
	std::string _wired;
	std::string _unused;

public:

	std::string getPhysMem() const;
	std::string getWired() const;
	std::string getUnused() const;

	Ram();
	~Ram();
	Ram(Ram const & other);
	Ram & operator=(Ram const & other);

	void parse(std::string & strToParce);

};

#endif
