#pragma once
#include "GeomPolyline2D.h"

class GeomPolygon2D
{
private:
	GeomPolyline2D m_polyline;

public:
	//Default constructor
	GeomPolygon2D();

	GeomPolygon2D(GeomPolyline2D&);

	GeomPolyline2D getPolyline() { return m_polyline; }
};