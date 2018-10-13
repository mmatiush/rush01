#include <iostream>
#include "MLXDisplay.hpp"
#include "OSInfo.hpp"

int		main(int ac, char **av) {
	if (ac == 1)
		;// ncurses.run();
	if (ac == 2 && strcmp(av[1], "g"))
	{

		;// MLX.run();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [ g ]" << std::endl;
}
