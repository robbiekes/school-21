#include  "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed a(5.03f);
	// Fixed b(3);
	// std::cout << a / b << std::endl;

	Point a(0, 0);
	Point b(10, 30);
	Point c(20, 0);

	Point point(21, 25);

	std::cout << bsp(a, b, c, point);
	return 0;
}