#include "Animal.hpp"

Animal::Animal() : type("") { std::cout << "Animal default constructor called" << std::endl; };

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &other)
{
	if (this != &other)
		type = other.type;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void Animal::makeSound() const { std::cout << "*some sound*" << std::endl; }

const std::string& Animal::getType() const { return type; }
