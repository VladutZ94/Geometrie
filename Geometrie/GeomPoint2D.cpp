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

bool GeomPoint2D::operator < (GeomPoint2D& P) 
{
	if (this->x < P.x)
		return true;
	if (P.x < this->x)
		return false;
	if (this->y < P.y)
		return true;
	return false;
}

GeomPoint2D GeomPoint2D::vect(GeomPoint2D &P1, GeomPoint2D &P2)
{
	return GeomPoint2D(P2.getX() - P1.getX(), P2.getY() - P1.getY());
}

