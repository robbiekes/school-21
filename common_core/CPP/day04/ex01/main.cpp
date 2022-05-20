#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() 
{
	const Animal *array[6];
	array[0] = new Cat();
	array[1] = new Cat();
	array[2] = new Cat();
	array[3] = new Dog();
	array[4] = new Dog();
	array[5] = new Dog();

	//std::cout << std::endl;

	//for (int i = 0; i < 6; i++)
	//	array[i]->makeSound();

	for (int i = 0; i < 6; i++)
		delete array[i];

	return 0;
}