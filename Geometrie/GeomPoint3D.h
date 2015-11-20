#ifndef GEOMPOINT3D_H
#define GEOMPOINT3D_H
#include <iostream>

class GeomPoint3D
{
private:
	double x;
	double y;
	double z;


public:
	GeomPoint3D();
	GeomPoint3D(double, double, double);
	GeomPoint3D(const GeomPoint3D&);

	// Writes the Vector v into the output stream in the format (x,y,z) 
	// So it can be used by various iostream functions.
	friend std::ostream &operator << (std::ostream&, const GeomPoint3D&);

	// Distance to other point
	double distanceTo(GeomPoint3D&);

	friend bool operator == (const GeomPoint3D&, const GeomPoint3D&);

	double getX() const { return x; };
	double getY() const { return y; };
	double getZ() const { return z; };
};
#endif