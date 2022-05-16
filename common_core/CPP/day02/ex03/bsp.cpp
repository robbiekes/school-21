#include "Point.hpp"

/*
	Coordinates of a triangle: А(х1,у1), B(х2,у2), Point(х3,у3).  We need to know whether a Point is on the left or on the right of the line AB;
	The formula is: D = (х3 - х1) * (у2 - у1) - (у3 - у1) * (х2 - х1)

	- If D = 0, Point is on the line;
	- If D < 0, Point is on the left of the line
	- If D > 0, Point is on the right of the line

	We've been given the coordinates of a triangle ABC and a point P.
	Is the point P to the left of or to the right of both the lines AB and AC?
	If true, it can't be inside. If false, it is at least inside the "cones" that satisfy the condition. 
	Now since we know that a point inside a trigon (triangle) must be to the same side of AB as BC (and also CA), we check if they differ. 
	If they do, P can't possibly be inside, otherwise P must be inside.
*/

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	bool point_ab = (point.getX() - a.getX()) * (b.getY() - a.getY()) - (point.getY() - a.getY()) * (b.getX() - a.getX()) > 0; // point on the right of AB
	bool point_ac = (point.getX() - a.getX()) * (c.getY() - a.getY()) - (point.getY() - a.getY()) * (c.getX() - a.getX()) > 0; // point on the right of AC
	bool point_bc = (point.getX() - b.getX()) * (c.getY() - b.getY()) - (point.getY() - b.getY()) * (c.getX() - b.getX()) > 0; // point on the right of BC                                                                                                                  
	if (point_ac == point_ab)
		return false;
	if (point_bc != point_ab)
		return false;
	return true;
}