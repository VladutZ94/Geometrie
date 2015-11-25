#include "GeomLine2D.h"

GeomLine2D::GeomLine2D()
{
	startPoint = GeomPoint2D(0, 0);
	endPoint = GeomPoint2D(0, 0);
}

GeomLine2D::GeomLine2D(GeomPoint2D start, GeomPoint2D end)
{
	startPoint = start;
	endPoint = end;
}