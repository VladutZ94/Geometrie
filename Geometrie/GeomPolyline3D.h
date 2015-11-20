#pragma once
#include <vector>
#include "GeomPoint3D.h"

class GeomPolyline3D
{
private:
	std::vector<GeomPoint3D> m_Vectices;

	int m_NumberOfVertices;

	bool m_bIsClosed;

public:
	GeomPolyline3D();

	GeomPolyline3D(std::vector<GeomPoint3D>);

	void append(GeomPoint3D&);

	friend std::ostream &operator << (std::ostream&, const GeomPolyline3D&);

	std::vector<GeomPoint3D> getVertices() { return this->m_Vectices; }

	bool getVertexAt(int, GeomPoint3D&);

	void setClosed() { this->m_bIsClosed = true; }

	bool isClosed() { return m_bIsClosed; }

	int getNumberOfVertices() { return m_NumberOfVertices; }

};
