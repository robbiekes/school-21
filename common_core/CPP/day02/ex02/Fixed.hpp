#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int fixedPointNum;
	static const int bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &other);

	Fixed& operator=(const Fixed &other);
	bool operator>(const Fixed &right);
	bool operator<(const Fixed &right);
	

	int toInt( void ) const;
	float toFloat( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& shift, const Fixed &num);

#endif