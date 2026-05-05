#include <iostream>
#include <ctime>

int		main( void ) {

	std::srand(time(nullptr));

	int mystery_number = std::rand() % 100;
	int essai = 6;

	int input = 0;

	std::cout << "Bienvenue dans un jeu qui pue sa race !!" << std::endl;
	
	while (essai != 0)
	{
		std::cout << "Devine le nombre mystere : ";
		std::cin >> input;
		if (input < mystery_number)
		{
			essai--;
			std::cout << "C'est plus ! Nombre d'essai restant : " << essai << std::endl;
			continue;
		}
		else if (input > mystery_number)
		{
			essai--;
			std::cout << "C'est moins ! Nombre d'essai restant : " << essai << std::endl;
			continue;
		}
		else
		{
			std::cout << "Bien joue connard" << std::endl;
			return 0;
		}
	}
	if (essai == 0)
	{
		std::cout << "T'es naze mon gars" << std::endl;
	}
}