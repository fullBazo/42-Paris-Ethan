#include <iostream>

int	main(int ac, char **av) {

	if (ac >= 2)
	{
		for (int j = 1; j < ac; j++){
			std::string str = av[j];
			for (int i = 0; i < str.length(); ++i)
				std::cout << (char)std::toupper(str[i]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}