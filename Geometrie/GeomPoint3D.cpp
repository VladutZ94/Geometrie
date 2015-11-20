#include "GeomPoint3D.h"
#include <iostream>
#include <math.h>

GeomPoint3D::GeomPoint3D()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

GeomPoint3D::GeomPoint3D(double X, double Y, double Z)
{
	x = X;
	y = Y;
	z = Z;
}

GeomPoint3D::GeomPoint3D(const GeomPoint3D& point)
{
	this->x = point.x;
	this->y = point.y;
	this->z = point.z;
}

std::ostream &operator<<(std::ostream &os, const GeomPoint3D &point)
{
	os << '(' << point.getX() << ',' << point.getY() << ',' << point.getZ() << ")";
	return os;
}

double GeomPoint3D::distanceTo(GeomPoint3D& point)
{
	double ret;
	ret = sqrt((this->x - point.x) * (this->x - point.x) +
		(this->y - point.y) * (this->y - point.y) +
		(this->z - point.z) * (this->z - point.z));
	return ret;
}

bool operator==(const GeomPoint3D& rPoint, const GeomPoint3D& lPoint)
{
	if (rPoint.getX() == lPoint.getX() && rPoint.getY() == lPoint.getY() && rPoint.getZ() == lPoint.getZ())
	{
		return true;
	}
	return false;
}