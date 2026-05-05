#include "PhoneBook.hpp"
#include <iostream>

int main() {
	PhoneBook pb;
	std::string input;
	
	while (true)
	{
		std::cout << "PhoneBook > ";
		if (!(std::getline(std::cin, input)))
		{
			std::cout << "\nEOF detected, exiting program." << std::endl;
			return 0;
		}
		if (input == "ADD")
			pb.add_contact();
		else if (input == "SEARCH")
			pb.search_contact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
