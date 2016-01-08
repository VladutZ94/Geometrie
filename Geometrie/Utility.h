//header guard at start of header file
#pragma once

#include <iostream>
#include "GeomPoint3D.h"
#include "GeomPoint2D.h"
#include "GeomPolyline3D.h"
#include "GeomPolyline2D.h"
#include "GeomPolygon2D.h"

class Utility
{
private:
	Utility() {}

	Utility(Utility const&) = delete;

	void operator=(Utility const&) = delete;

public:
	static Utility& getInstance()
	{
		static Utility instance; // Guaranteed to be destroyed.
							  // Instantiated on first use.
		return instance;
	}

	//                        A                     P                   B            r
	bool isCollinear(GeomPoint3D& , GeomPoint3D& , GeomPoint3D&);

	bool isPolygonConvex(GeomPolyline2D&);

	double getAreaOfATriangle(GeomPoint2D&, GeomPoint2D&, GeomPoint2D&);

	bool getConvexHull(std::vector<GeomPoint2D>&, GeomPolyline2D&);

	bool bigProject(GeomPolygon2D&, GeomPolygon2D&);

};
