#include "GeomPolygon2D.h"

GeomPolygon2D::GeomPolygon2D()
{
	m_polyline = GeomPolyline2D();
	m_polyline.setClosed();
}

GeomPolygon2D::GeomPolygon2D(GeomPolyline2D& poly)
{
	m_polyline = poly;
	m_polyline.setClosed();
}

