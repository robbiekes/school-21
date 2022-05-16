#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	Fixed x;
	Fixed y;

public:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Point &other);
	const Point& operator=(const Point &other);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif