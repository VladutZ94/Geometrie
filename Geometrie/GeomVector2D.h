#pragma once
#include "GeomPoint2D.h"

class GeomVector2D
{
private:
	double x;
	double y;


public:
	GeomVector2D();

	GeomVector2D(double, double);

	GeomVector2D(GeomPoint2D&);

	GeomVector2D(GeomPoint2D&, GeomPoint2D&);

	GeomVector2D(const GeomVector2D&);

	double getX() const { return x; }

	double getY() const { return y; }

	GeomVector2D& operator +=(const GeomVector2D&);

	GeomVector2D& operator +(const GeomVector2D&);

	double cross_product( GeomVector2D&,  GeomVector2D&);

	double dot_product(GeomVector2D&, GeomVector2D&);

	bool isCollinear(GeomVector2D&);
	
	//GeomVector2D asVector() { return GeomVector2D(*this); }

	friend GeomVector2D operator * (const GeomVector2D&, double);
	friend GeomVector2D operator * (double, const GeomVector2D&);

	friend std::ostream &operator <<(std::ostream& os, const GeomVector2D&);
};