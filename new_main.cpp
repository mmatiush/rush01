#include <iostream>

int		main(int ac, char **av) {
	if (ac == 1)
		std::cout << "ncurses" << std::endl;
		// ncurses.run();
	else if (ac == 2 && (strcmp(av[1], "g") == 0))
		std::cout << "MLX" << std::endl;
		// MLX.run();
	else
		std::cout << "Usage: ./ft_gkrellm [ g ]" << std::endl;

	return (0);
}
