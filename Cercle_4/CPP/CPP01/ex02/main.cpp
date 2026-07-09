#include <iostream>


int main( void ) {

	std::string STR = "HI THIS IS BRAIN";
	std::string *stringPTR = &STR;
	std::string &stringREF = STR;

	std::cout << "Address :" << std::endl;

	std::cout << &STR << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << "Values :" << std::endl;

	std::cout << STR << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}
