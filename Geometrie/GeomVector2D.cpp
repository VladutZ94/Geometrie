#include <iostream>
#include "GeomVector2D.h"

GeomVector2D::GeomVector2D()
{
	x = 0;
	y = 0;
}

GeomVector2D::GeomVector2D(double X, double Y)
{
	this->x = X;
	this->y = Y;
}

GeomVector2D::GeomVector2D(const GeomVector2D& vec)
{
	this->x = vec.x;
	this->y = vec.y;
}

GeomVector2D operator+(const GeomVector2D &v1, const GeomVector2D &v2)
{
	return GeomVector2D(v1.getX() + v2.getX(), v1.getY() + v2.getY());
}

GeomVector2D &GeomVector2D::operator +=(const GeomVector2D& vec)
{
	this->x += vec.getX();
	this->y += vec.getY();
	return *this;
}