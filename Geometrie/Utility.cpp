#include <math.h>
#include <algorithm>
#include <Windows.h>
#include "Utility.h"
#include "GeomVector2D.h"
#include "GeomVector3D.h"


bool Utility::isCollinear(GeomPoint3D& A, GeomPoint3D& B, GeomPoint3D& C)
{
	GeomVector3D AB(B.getX() - A.getX(),
					B.getY() - A.getY(),
					B.getZ() - A.getZ());

	GeomVector3D AC(C.getX() - A.getX(),
					C.getY() - A.getY(),
					C.getZ() - A.getZ());
	if (AB.CrossProduct(AC).Length() == 0)
	{
		if (A == B)
		{
			return true;
		}
		if (A == C)
		{
			return true;
		}
		if (B == C)
		{
			return true;
		}
		return true;
	}
	return false;
}

// Not sure if is a good thing going here =))
bool Utility::isPolygonConvex(GeomPolyline2D& poly)
{
	if (poly.getNumberOfVertices() < 3 || !poly.isClosed())
	{
		return false;
	}

	GeomPoint2D p, u, v;
	double res = 0;
	for (int i = 0; i < poly.getNumberOfVertices(); i++)
	{
		poly.getVertexAt(i, p);
		GeomPoint2D temp;
		poly.getVertexAt((i + 1) % poly.getNumberOfVertices(), temp);
		GeomPoint2D v(temp.getX() - p.getX(), temp.getY() - p.getY());
		poly.getVertexAt((i + 2) % poly.getNumberOfVertices(), u);

		if (i == 0) // in first loop direction is unknown, so save it in res
			res = u.getX() * v.getY() - u.getY() * v.getX() + v.getX() * p.getY() - v.getY() * p.getX();
		else
		{
			double newres = u.getX() * v.getY() - u.getY() * v.getX() + v.getX() * p.getY() - v.getY() * p.getX();
			if ((newres > 0 && res < 0) || (newres < 0 && res > 0))
			{
				return false;
			}
		}
	}
	return true;
}

double Utility::getAreaOfATriangle(GeomPoint2D& A, GeomPoint2D& B, GeomPoint2D& C)
{
	double area = 0;

	area += A.getX() * B.getY();
	area += B.getX() * C.getY();
	area += C.getX() * A.getY();

	area -= C.getX() * B.getY();
	area -= B.getX() * A.getY();
	area -= A.getX() * C.getY();

	return abs(area);
}


// shit for convex hull
// V is the vector of points
// N is the size of V
std::vector<GeomPoint2D> V;
int N;

bool cmp( GeomPoint2D &P1,  GeomPoint2D &P2)
{
	return GeomVector2D().cross_product( GeomVector2D(V[1], P1), GeomVector2D(V[1], P2) ) < 0;
}

void _sort()
{
	int poz = 1;
	for (int i = 2; i <= N; i++)
	{
		if (V[i] < V[poz])
		{
			poz = i;
		}
	}
	std::swap(V[1], V[poz]);
	std::sort(V.begin() + 1, V.end(), cmp);
}

bool Utility::getConvexHull(std::vector<GeomPoint2D>& convexHull, GeomPolyline2D& poly)
{
	V = poly.getVertices();
	N = V.size();
	V.push_back(GeomPoint2D());
	for (unsigned i = N; i > 0; i--)
	{
		std::swap(V[i], V[i - 1]);
	}

	std::vector<GeomPoint2D> st;
	_sort();
	st.push_back(V[1]);
	st.push_back(V[2]);
	for (int i = 3; i <= N; i++)
	{
		while (st.size() > 1 && GeomVector2D().cross_product(GeomVector2D(st[st.size() - 2], st[st.size() - 1]), GeomVector2D(st[st.size() - 2], V[i])) > 0)
		{
			st.pop_back();
		}
		st.push_back(V[i]);

	}

	convexHull = st;
	return true;
}

bool Utility::bigProject(GeomPolygon2D& firstPolygon, GeomPolygon2D& secondPolygon)
{
	GeomPolyline2D polylineForConvexHull;

	polylineForConvexHull = firstPolygon.getPolyline();
	polylineForConvexHull.append(secondPolygon.getPolyline());

	std::vector<GeomPoint2D> convexHull;
	getConvexHull(convexHull, polylineForConvexHull);

	std::reverse(convexHull.begin(), convexHull.end());
	for (auto it : convexHull)
	{
		std::cout << it <<"->";
	}

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << convexHull[0];
	SetConsoleTextAttribute(hConsole, 7);
	std::cout << "=(start)\n";


	return false;
}