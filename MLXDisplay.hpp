#ifndef MLXDISPLAY_HPP
# define MLXDISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "IMonitorModule.hpp"
# include "OSInfo.hpp"
# include "TimeModule.hpp"
# include "HostUserNames.hpp"
# include "RAM.hpp"
# include "CPU.hpp"
# include "Network.hpp"
# include <vector>

class MLXDisplay : public IMonitorDisplay
{

private:

	std::vector<IMonitorModule *> _modules;

public:

	std::vector<IMonitorModule *> getModules() const;

	MLXDisplay();
	~MLXDisplay();
	MLXDisplay(MLXDisplay const & other);
	MLXDisplay & operator=(MLXDisplay const & other);

	void	displayHostUserName( void );
	void	displayNetwork( void );
	void	displayCPU( void );
	void	displayRAM( void );
	void	displayOSinfo( void );
	void	displayTime( void );

};

#endif
