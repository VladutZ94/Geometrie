#include <iostream>
#include "GeomVector2D.h"
#include "GeomPoint2D.h"

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

GeomVector2D::GeomVector2D(GeomPoint2D& P1, GeomPoint2D& P2)
{
	GeomPoint2D point = GeomPoint2D().vect(P1, P2);
	this->x = point.getX();
	this->y = point.getY();
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

double GeomVector2D::cross_product(GeomVector2D& V1, GeomVector2D& V2)
{
	return (V1.getX() * V2.getY() - V1.getY() * V2.getX());
}