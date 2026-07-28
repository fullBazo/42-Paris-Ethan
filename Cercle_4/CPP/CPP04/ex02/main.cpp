#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "-----Construction Initiale-----" << std::endl << std::endl;

	// AAnimal test;

	int			size = 2;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	AAnimal		*array[size];
	Dog			original;

	std::cout << std::endl;
	std::cout << "-----TEST COPY-----" << std::endl << std::endl;


	original.getBrain()->setIdeas(0, "original idea");

	Dog			copy(original);

	std::cout << "Original: " << original.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Copy avant modif: " << copy.getBrain()->getIdeas(0) << std::endl;

	original.getBrain()->setIdeas(0, "modified idea");  // on change SEULEMENT l'original

	std::cout << "Original apres modif: " << original.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Copy apres modif original: " << copy.getBrain()->getIdeas(0) << std::endl << std::endl;
	
	std::cout << "-----TEST OPERATOR-----" << std::endl << std::endl;

	Dog another;
	another = original;  // teste operator=, pas le constructeur de copie
	another.getBrain()->setIdeas(0, "another original idea");
	std::cout << "another devient: " << another.getBrain()->getIdeas(0) << std::endl;
	std::cout << "Original apres modif via another: " << original.getBrain()->getIdeas(0) << std::endl << std::endl;

	std::cout << "-----ARRAY DE DOG/CAT-----" << std::endl << std::endl;

	for (int i = 0; i < (size / 2); i++)
	{

		array[i] = new Dog();
	}
	for (int i = size / 2; i < size; i++)
	{
		array[i] = new Cat();
	}
	
	( void )array;

	std::cout << std::endl;
	std::cout << "-----DESTRUCTION-----" << std::endl << std::endl;

	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	
	delete j;//should not create a leak
	delete i;

	return 0;
}