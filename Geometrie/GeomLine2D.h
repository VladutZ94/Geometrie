#pragma once
#include "GeomPoint2D.h"

// To be continued by m3
// The line is infinit, so i must get teh ecuation of the segment represented by the two point
class GeomLine2D
{
private:
	GeomPoint2D startPoint;
	GeomPoint2D endPoint;

public:
	GeomLine2D();
	GeomLine2D(GeomPoint2D , GeomPoint2D );

};