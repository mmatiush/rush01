#include <iostream>
#include "MLXDisplay.hpp"
#include "OSInfo.hpp"
#include "TimeModule.hpp"
#include "IMonitorModule.hpp"

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
		std::cout << "ncurses" << std::endl;
		TimeModule t;

		std::string s = exec("top");
		t.parse(s);
		// ncurses.run();
	}
	else if (ac == 2 && (strcmp(av[1], "g") == 0))
	{
		std::cout << "MLX" << std::endl;
		// MLX.run();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [ g ]" << std::endl;

	return (0);
}
