#pragma once
#include "GeomPoint2D.h"
#include "GeomVector2D.h"

class GeomSegment2D
{
private:
	GeomPoint2D m_start, m_end;
	GeomVector2D m_direction;

public:
	GeomSegment2D();

	GeomSegment2D(GeomPoint2D&, GeomPoint2D&);

	GeomVector2D getDirection() { return m_direction; }

	bool isParalel(GeomSegment2D&);

};