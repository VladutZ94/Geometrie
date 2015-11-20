#pragma once

class GeomVector2D
{
private:
	double x;
	double y;


public:
	GeomVector2D();

	GeomVector2D(double, double);

	GeomVector2D(const GeomVector2D&);

	double getX() const { return x; }

	double getY() const { return y; }

	GeomVector2D& operator +=(const GeomVector2D&);

	GeomVector2D& operator +(const GeomVector2D&);


};