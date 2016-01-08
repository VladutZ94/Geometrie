#pragma once
#include <vector>
#include "GeomPoint2D.h"

class GeomPolyline2D
{
private:
	std::vector<GeomPoint2D> m_Vectices;

	int m_NumberOfVertices;

	bool m_bIsClosed;

public:
	GeomPolyline2D();

	GeomPolyline2D(std::vector<GeomPoint2D>);

	void append(GeomPoint2D&);

	void append(GeomPolyline2D&);

	friend std::ostream &operator << (std::ostream&, const GeomPolyline2D&);

	std::vector<GeomPoint2D> getVertices() { return this->m_Vectices; }

	bool getVertexAt(int, GeomPoint2D&);

	void setClosed() { this->m_bIsClosed = true; }

	bool isClosed() { return m_bIsClosed; }

	int getNumberOfVertices() { return m_NumberOfVertices; }

	bool isInside(GeomPoint2D&);

	GeomPoint2D top() { return m_Vectices.back(); }

	void pop();
};
