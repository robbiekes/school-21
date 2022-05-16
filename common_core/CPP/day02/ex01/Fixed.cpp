#include "Fixed.hpp"

/* Notes:
 	 shifting the bit pattern of a number to the right by 1 bit
	 always divides the number by 2

	 shifting the bit pattern of a number to the left by 1 bit
	 always multiplies the number by 2
*/

/*
Converting from fixed-point to float-point:
We take the input value and divide it by (2^fractional_bits), putting the result into a float:

float fixed_to_float (fixed_point input)
{
    return ((float)input / (float)(1 << 8));
}

To convert from floating-point to fixed-point, we follow this algorithm:

Calculate x = floating_input * 2^(fractional_bits)
Round x to the nearest whole number (e.g. round(x))
Store the rounded x in an integer container
*/

Fixed::Fixed() : fixedPointNum(0) { std::cout << "Default constructor called" << std::endl; }
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
Fixed::Fixed(const Fixed &other) : fixedPointNum(other.fixedPointNum) { std::cout << "Copy constructor called" << std::endl; }

Fixed::Fixed(const int num)
{
	std::cout << "A constant integer constructor called" << std::endl;
	fixedPointNum = num << bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "A constant float constructor called" << std::endl;
	fixedPointNum = roundf(num * (1 << bits));
}

int Fixed::toInt() const
{
	return fixedPointNum >> bits;
}

float Fixed::toFloat() const 
{
	return (float) fixedPointNum / (float) (1 << bits);
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

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNum = other.fixedPointNum;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}