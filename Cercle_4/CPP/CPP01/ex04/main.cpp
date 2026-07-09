#include <iostream>
#include <fstream>

int	main( int ac, char **av ) {

	if (ac == 2) {
		std::string		line;
		std::ifstream	file(av[1]);
		if(!file.is_open()) {
			std::cerr << "Error : cannot open file" << std::endl;
			return 1;
		}
		while (std::getline(file, line)) {
			size_t pos = line.find(av[2]);
			if (pos != std::string::npos)
				std::cerr << "Error : occurence(s) not found";
			else
			{
				found 
			}
		}
		return 0;
	}
	else
		return 1;

}
