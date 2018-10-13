#ifndef MLXDISPLAY_HPP
# define MLXDISPLAY_HPP
# include <iostream>
# include <string>
# include "IMonitorDisplay.hpp"

class MLXDisplay : public IMonitorDisplay
{

public:

	MLXDisplay();
	~MLXDisplay();
	MLXDisplay(MLXDisplay const & other);
	MLXDisplay & operator=(MLXDisplay const & other);

};

#endif
