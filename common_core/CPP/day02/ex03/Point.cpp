#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::~Point() {}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point &other) { *this = other; }
const Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

Fixed Point::getX() const { return x; }
Fixed Point::getY() const { return y; }
