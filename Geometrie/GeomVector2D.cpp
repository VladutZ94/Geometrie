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

GeomVector2D::GeomVector2D(GeomPoint2D& point)
{
	this->x = point.getX();
	this->y = point.getY();
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

GeomVector2D &GeomVector2D::operator+(const GeomVector2D &v1)
{
	return GeomVector2D(v1.getX() + this->getX(), v1.getY() + this->getY());
}

GeomVector2D &GeomVector2D::operator +=(const GeomVector2D& vec)
{
	this->x += vec.getX();
	this->y += vec.getY();
	return *this;
}

GeomVector2D operator*(double scalar, const GeomVector2D &v)
{
	return GeomVector2D(v.getX()*scalar, v.getY()*scalar);
}

GeomVector2D operator*(const GeomVector2D &v, double scalar)
{
	return GeomVector2D(v.getX()*scalar, v.getY()*scalar);
}

// magnitude of the 3D cross product
double GeomVector2D::cross_product(GeomVector2D& V1, GeomVector2D& V2)
{
	return (V1.getX() * V2.getY() - V1.getY() * V2.getX());
}

double GeomVector2D::dot_product(GeomVector2D& v1, GeomVector2D& v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY();
}

bool GeomVector2D::isCollinear(GeomVector2D& vec)
{
	if (cross_product(*this, vec) == 0)
	{
		return true;
	}

	return false;
}

std::ostream &operator<<(std::ostream &os, const GeomVector2D& vector)
{
	os << '(' << vector.getX() << ',' << vector.getY() << ")";
	return os;
}