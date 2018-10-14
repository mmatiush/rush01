# include "main.hpp"

int		main(int ac, char **av) {

	if (ac == 1) {
		TerminalDisplay t;
		t.run();
	}
	else if (ac == 2 && (strcmp(av[1], "g") == 0)) {
		SFMLDisplay sfml;
		sfml.display();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [ g ]" << std::endl;

	// system("leaks --quiet ft_gkrellm");
	return (0);
}
