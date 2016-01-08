#pragma once
#include "GeomPoint3D.h"
#include "GeomPolygon2D.h"


class Laborator
{
private:

public:
	//First project
	bool Laborator1(GeomPoint3D &, GeomPoint3D &, GeomPoint3D &);

	//Second project
	bool Laborator2(GeomPolygon2D&, GeomPoint2D&);

	//Third Project
	bool Laborator3(GeomPoint2D&, GeomPoint2D&, GeomPoint2D&, GeomPoint2D&);

	//Fourth project
	bool Laborator4(GeomPoint2D&, GeomPoint2D&, GeomPoint2D&, GeomPoint2D&);

};