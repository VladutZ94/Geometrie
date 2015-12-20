#pragma once
#include <iostream>


class GeomPoint2D
{
private:
	double x;
	double y;


public:
	GeomPoint2D();

	GeomPoint2D(double, double);

	GeomPoint2D(const GeomPoint2D&);

	double getX() const { return x; }

	double getY() const { return y; }

	friend std::ostream &operator <<(std::ostream& os, const GeomPoint2D&);

	bool operator < (GeomPoint2D& b);

	GeomPoint2D vect(GeomPoint2D &P1, GeomPoint2D &P2);
};