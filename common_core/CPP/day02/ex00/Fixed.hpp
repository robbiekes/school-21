#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixedPointNum;
	static const int bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &other); // copy constructor

	Fixed& operator=(const Fixed &other); // overloaded operator=

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif