#include "GeomPolyline2D.h"
#include "Utility.h"


GeomPolyline2D::GeomPolyline2D()
{
	m_NumberOfVertices = 0;
	m_Vectices.empty();
	m_bIsClosed = false;
}

GeomPolyline2D::GeomPolyline2D(std::vector<GeomPoint2D> polyline)
{
	m_Vectices = polyline;
	m_NumberOfVertices = (int)polyline.size();
	m_bIsClosed = false;
}

void GeomPolyline2D::append(GeomPoint2D& point)
{
	this->m_Vectices.push_back(point);
	this->m_NumberOfVertices++;
}

std::ostream &operator<<(std::ostream &os, const GeomPolyline2D& p)
{
	for (auto it = 0; it < p.m_NumberOfVertices; it++)
	{
		os << p.m_Vectices[it];
	}
	return os;
}

bool GeomPolyline2D::getVertexAt(int i, GeomPoint2D& point)
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

// For the moment this is implemented only for 
// A polyline with 3 or 4 vertices
bool GeomPolyline2D::isInside(GeomPoint2D& point)
{
	if (!this->m_bIsClosed)
	{
		return false;
	}
	if (this->m_NumberOfVertices == 3)
	{
		double bigArea = 
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[1], this->m_Vectices[2]);
		double firstSmallArea =
			Utility::getInstance().getAreaOfATriangle(point, this->m_Vectices[1], this->m_Vectices[2]);
		double secondSmallArea =
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], point, this->m_Vectices[2]);
		double thirdSmallArea =
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[1], point);
		if (bigArea == firstSmallArea + secondSmallArea + thirdSmallArea)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (this->m_NumberOfVertices == 4)
	{
		double bigArea =
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[1], this->m_Vectices[2]);
		double firstSmallArea =
			Utility::getInstance().getAreaOfATriangle(point, this->m_Vectices[1], this->m_Vectices[2]);
		double secondSmallArea =
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], point, this->m_Vectices[2]);
		double thirdSmallArea =
			Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[1], point);
		if (bigArea == firstSmallArea + secondSmallArea + thirdSmallArea)
		{
			return true;
		}
		else
		{
			double bigArea =
				Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[3], this->m_Vectices[2]);
			double firstSmallArea =
				Utility::getInstance().getAreaOfATriangle(point, this->m_Vectices[3], this->m_Vectices[2]);
			double secondSmallArea =
				Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], point, this->m_Vectices[2]);
			double thirdSmallArea =
				Utility::getInstance().getAreaOfATriangle(this->m_Vectices[0], this->m_Vectices[3], point);
			if (bigArea == firstSmallArea + secondSmallArea + thirdSmallArea)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void GeomPolyline2D::pop()
{
	if (m_NumberOfVertices != 0)
	{
		m_Vectices.pop_back();
		m_NumberOfVertices--;
	}
}