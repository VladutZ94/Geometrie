#include "GeomPolyline3D.h"

GeomPolyline3D::GeomPolyline3D()
{
	m_NumberOfVertices = 0;
	m_Vectices.empty();
	m_bIsClosed = false;
}

GeomPolyline3D::GeomPolyline3D(std::vector<GeomPoint3D> polyline)
{
	m_Vectices = polyline;
	m_NumberOfVertices = (int)polyline.size();
	m_bIsClosed = false;
}

void GeomPolyline3D::append(GeomPoint3D& point)
{
	this->m_Vectices.push_back(point);
	this->m_NumberOfVertices++;
}

std::ostream &operator<<(std::ostream &os, const GeomPolyline3D& p)
{
	for (auto it = 0; it < p.m_NumberOfVertices; it++)
	{
		os << p.m_Vectices[it];
	}
	return os;
}

bool GeomPolyline3D::getVertexAt(int i, GeomPoint3D& point)
{
	if (this->m_NumberOfVertices > i)
	{
		point = this->m_Vectices[i];
		return true;
	}
	else
	{
		return false;
	}
}