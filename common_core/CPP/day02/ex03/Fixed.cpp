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

Fixed::Fixed() : fixedPointNum(0) {}
Fixed::~Fixed() {}
Fixed::Fixed(const Fixed &other) : fixedPointNum(other.fixedPointNum) {}

Fixed::Fixed(const int num)
{
	fixedPointNum = num << bits;
}

Fixed::Fixed(const float num)
{
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
	return fixedPointNum;
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPointNum = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->fixedPointNum = other.fixedPointNum;
	return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->fixedPointNum > other.fixedPointNum;
	// int k = this->fixedPointNum - other.fixedPointNum;
	// return k > 0;
}

bool Fixed::operator<(const Fixed &other) const
{
	return other.fixedPointNum > this->fixedPointNum;
}

bool Fixed::operator>=(const Fixed &other) const
{
	return !(this->fixedPointNum < other.fixedPointNum);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return !(this->fixedPointNum > other.fixedPointNum);
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->fixedPointNum == other.fixedPointNum;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return !(this->fixedPointNum == other.fixedPointNum);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed tmp(this->toFloat() + other.toFloat());
	return tmp;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed tmp(this->toFloat() - other.toFloat());
	return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed tmp(this->toFloat() * other.toFloat());
	return tmp;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed tmp(this->toFloat() / other.toFloat());
	return tmp;
}

Fixed& Fixed::operator++()
{
	this->fixedPointNum++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->fixedPointNum;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->fixedPointNum--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--this->fixedPointNum;
	return tmp;
}

Fixed& Fixed::min(Fixed &left, Fixed &right)
{
	return left < right ? left : right;
}

const Fixed& Fixed::min(const Fixed &left, const Fixed &right)
{
	if (left.fixedPointNum < right.fixedPointNum)
		return left;
	else
		return right;
}

Fixed& Fixed::max(Fixed &left, Fixed &right)
{
	return left > right ? left : right;
}

const Fixed& Fixed::max(const Fixed &left, const Fixed &right)
{
	if (left.fixedPointNum > right.fixedPointNum)
		return left;
	else
		return right;
}

std::ostream& operator<<(std::ostream& out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}