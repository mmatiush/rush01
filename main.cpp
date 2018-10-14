# include "main.hpp"

std::string exec(const char* cmd) {

	char buffer[1000];
	std::string result = "";
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		throw std::runtime_error("popen() failed!");

	for (int i = 0; i < 10; i++)
		if (fgets(buffer, 1000, pipe) != NULL)
			result += buffer;
	pclose(pipe);

	return result;
}

int		main(int ac, char **av) {

	if (ac == 1) {
		// TimeModule t;
		// HostUserNames n;
		// RAM r;
		// CPU c;
		// Network e;
		// OSInfo o;
		
		TerminalDisplay t1;

		t1 = TerminalDisplay();

		TerminalDisplay t;
		t.run();

		// std::string s = exec("top");
		// std::cout << s << std::endl;
		// t.parse(s);
		// std::cout << t.getTime() << std::endl;
		// std::cout << t.getDate() << std::endl;
		// std::cout << std::endl;

		// n.parse(s);
		// std::cout << n.getHostName() << std::endl;
		// std::cout << n.getUserName() << std::endl;
		// std::cout << std::endl;

		// r.parse(s);
		// std::cout << r.getPhysMem() << std::endl;
		// std::cout << r.getWired() << std::endl;
		// std::cout << r.getUnused() << std::endl;
		// std::cout << std::endl;

		// c.parse(s);
		// std::cout << c.getCpuBrand() << std::endl;
		// std::cout << c.getAvg1() << std::endl;
		// std::cout << c.getAvg5() << std::endl;
		// std::cout << c.getAvg15() << std::endl;
		// std::cout << c.getUsageUser() << std::endl;
		// std::cout << c.getUsageSys() << std::endl;
		// std::cout << c.getUsageIdle() << std::endl;
		// std::cout << std::endl;

		// e.parse(s);
		// std::cout << e.getPacketsIn() << std::endl;
		// std::cout << e.getPacketsOut() << std::endl;
		// std::cout << std::endl;

		
		// std::cout << o.getProductName() << std::endl;
		// std::cout << o.getBuildVersion() << std::endl;
		// std::cout << o.getProductVersion() << std::endl;
		// std::cout << o.getKernelVersion() << std::endl;
		// std::cout << std::endl;
		// ncurses.run();
	}
	else if (ac == 2 && (strcmp(av[1], "g") == 0))
	{
		SFMLDisplay sfml;

		sfml.display();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [ g ]" << std::endl;

	// system("leaks --quiet ft_gkrellm");
	return (0);
}
