#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("") { std::cout << "WrongAnimal default constructor called" << std::endl; };

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const { std::cout << "*some sound*" << std::endl; }

const std::string& WrongAnimal::getType() const { return type; }
