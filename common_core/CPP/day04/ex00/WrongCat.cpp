# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		type = other.type;
	return *this;
	std::cout << "WrongCat assignment operator called" << std::endl;
}

void WrongCat::makeSound() const { std::cout << "meooow" << std::endl; }

const std::string& WrongCat::getType() const { return type; }