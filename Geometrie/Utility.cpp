#include "Utility.h"
#include "GeomVector3D.h"
#include <math.h>
#include <algorithm>

bool Utility::isCollinear(GeomPoint3D& A, GeomPoint3D& B, GeomPoint3D& C, double& alpha)
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
			alpha = 1;
			return true;
		}
		if (A == C)
		{
			alpha = 0;
			return true;
		}
		if (B == C)
		{
			alpha = -1;
			return true;
		}
		GeomVector3D CB(B.getX() - C.getX(),
						B.getY() - C.getY(),
						B.getZ() - C.getZ());

		GeomVector3D CA = -AC;
		alpha = CA.Length() / CB.Length();
		if (alpha > 1)
		{
			alpha = CB.Length() / CA.Length();
		}
		return true;
	}
	return false;
}

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

GeomPoint2D pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn(left turn),
// +1 for a clockwise turn (right turn), 0 if they are collinear
double ccw(const GeomPoint2D& p1, const GeomPoint2D& p2, const GeomPoint2D& p3)
{
	double area = (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX()- p1.getX());
	if (area > 0)
		return -1;
	else if (area < 0)
		return 1;
	return 0;
}

int cmp(const GeomPoint2D& p1, const GeomPoint2D& p2) {
	return ccw(pivot, p1, p2) < 0;
}

// returns square of Euclidean distance between two points
double sqrDist(GeomPoint2D& a, GeomPoint2D& b) {
	double dx = a.getX() - b.getX();
	double dy = a.getY() - b.getY();
	return dx * dx + dy * dy;
}

bool POLAR_ORDER(GeomPoint2D a, GeomPoint2D b) {
	double order = ccw(pivot, a, b);
	if (order == 0)
		return sqrDist(pivot, a) < sqrDist(pivot, b);
	return (order == -1);
}

bool Utility::getConvexHull(std::vector<GeomPoint2D>& pointArray, GeomPolyline2D& ConvexHull)
{
	if (pointArray.size() < 3)
	{
		return false;
	}

	// find the point having the least y coordinate (pivot),
	// ties are broken in favor of lower x coordinate
	int leastY = 0;
	for (unsigned i = 1; i < pointArray.size(); i++)
		if (pointArray[i] < pointArray[leastY])
			leastY = i;

	// swap the pivot with the first point
	GeomPoint2D temp = pointArray[0];
	pointArray[0] = pointArray[leastY];
	pointArray[leastY] = temp;

	// sort the remaining point according to polar order about the pivot
	pivot = pointArray[0];
	std::sort(pointArray.begin(), pointArray.end(), POLAR_ORDER);

	ConvexHull.append(pointArray[0]);
	ConvexHull.append(pointArray[1]);


	ConvexHull.append(pointArray[2]);

	for (unsigned i = 3; i < pointArray.size(); i++) {
		GeomPoint2D top = ConvexHull.top();
		ConvexHull.pop();
		while (ccw(ConvexHull.top(), top, pointArray[i]) != -1) {
			top = ConvexHull.top();
			ConvexHull.pop();
		}
		ConvexHull.append(top);
		ConvexHull.append(pointArray[i]);
	}
	ConvexHull.setClosed();
	return true;
}