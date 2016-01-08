#include "GeomSegment2D.h"

GeomSegment2D::GeomSegment2D()
{
	m_start = GeomPoint2D(0, 0);
	m_end = GeomPoint2D(0, 0);
	m_direction = GeomVector2D(m_start, m_end);
}

GeomSegment2D::GeomSegment2D(GeomPoint2D& start, GeomPoint2D& end)
{
	m_start = start;
	m_end = end;
	m_direction = GeomVector2D(start, end);
}

bool GeomSegment2D::isParalel(GeomSegment2D& seg)
{
	if (m_direction.isCollinear(seg.m_direction))
	{
		return true;
	}
	return false;
}