#ifndef CPU_HPP
# define CPU_HPP

# include "IMonitorModule.hpp"
# include <string>

class CPU : public IMonitorModule
{

private:

	std::string _cpuBrand;
	std::string _avg1;
	std::string _avg5;
	std::string _avg15;
	std::string _usageUser;
	std::string _usageSys;
	std::string _usageIdle;

public:

	std::string getCpuBrand() const;
	std::string getAvg1() const;
	std::string getAvg5() const;
	std::string getAvg15() const;
	std::string getUsageUser() const;
	std::string getUsageSys() const;
	std::string getUsageIdle() const;

	CPU();
	~CPU();
	CPU(CPU const & other);
	CPU & operator=(CPU const & other);

	void parse(std::string & strToParce);

};

#endif

// Processes: 287 total, 2 running, 285 sleeping, 1546 threads
// 2018/10/13 20:53:14
// Load Avg: 2.20, 1.99, 1.87
// CPU usage: 20.0% user, 25.45% sys, 54.54% idle
// SharedLibs: 144M resident, 51M data, 19M linkedit.
// MemRegions: 53032 total, 3421M resident, 125M private, 1216M shared.
// PhysMem: 7841M used (1432M wired), 350M unused.
// VM: 1811G vsize, 1097M framework vsize, 512(0) swapins, 512(0) swapouts.
// Networks: packets: 322177/379M in, 172866/75M out.
// Disks: 94850/3612M read, 48487/1243M written.