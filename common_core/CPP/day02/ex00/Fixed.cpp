#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &other) : fixedPointNum(other.fixedPointNum) { std::cout << "Copy constructor called" << std::endl; }
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNum = other.fixedPointNum;
	return *this;
}
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointNum;
}
void Fixed::setRawBits( int const raw )
{
	std::cout << "getRawBits member function called" << std::endl;
	this->fixedPointNum = raw;
}