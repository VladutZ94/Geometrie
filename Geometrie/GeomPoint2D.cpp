#include "GeomPoint2D.h"
#include <iostream>


GeomPoint2D::GeomPoint2D()
{
	x = 0;
	y = 0;
}

GeomPoint2D::GeomPoint2D(double X, double Y)
{
	x = X;
	y = Y;
}

GeomPoint2D::GeomPoint2D(const GeomPoint2D& point)
{
	this->x = point.x;
	this->y = point.y;
}

std::ostream &operator<<(std::ostream &os, const GeomPoint2D& point)
{
	os << '(' << point.getX() << ',' << point.getY() << ")";
	return os;
}

bool GeomPoint2D::operator < (GeomPoint2D& b) {
	if (y != b.y)
		return y < b.y;
	return x < b.x;
}
