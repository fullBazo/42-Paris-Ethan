#include <iostream>
#include <fstream>

int main( int ac, char **av )
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./program <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: cannot open file" << std::endl;
		return 1;
	}

	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string content;
	std::string line;

	while (std::getline(file, line))
		content += line + "\n";

	std::string result;
	size_t		pos = 0;
	size_t		found;
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.size();
	}
	result += content.substr(pos);

	std::string outputName = std::string(av[1]) + ".replace";
	std::ofstream outFile(outputName);
	outFile << result;

	return 0;
}
