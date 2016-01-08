#include <math.h>
#include "Laborator.h"
#include "Utility.h"
#include "GeomPolyline2D.h"
#include "GeomSegment2D.h"
#include "GeomVector2D.h"

// Laborator 1
// In 3D daca trei puncte sunt coliniare si ecuatia afina dintre ele
bool Raport(GeomPoint3D& pt1, GeomPoint3D& pt2, GeomPoint3D& pt3, double& alpha)
{
	if (pt1.getX() - pt3.getX() != 0)
	{
		alpha = (pt1.getX() - pt2.getX()) / (pt1.getX() - pt3.getX());
		return true;
	}

	if (pt1.getY() - pt3.getY() != 0)
	{
		alpha = (pt1.getY() - pt2.getY()) / (pt1.getY() - pt3.getY());
		return true;
	}

	if (pt1.getZ() - pt3.getZ() != 0)
	{
		alpha = (pt1.getZ() - pt2.getZ()) / (pt1.getZ() - pt3.getZ());
		return true;
	}
	return false;
}
bool Laborator::Laborator1(GeomPoint3D &A, GeomPoint3D &B, GeomPoint3D &C)
{
	if (A == B)
	{
		std::cout << "A = 1*B + 0*C\n";
		return true;
	}

	if (A == C)
	{
		std::cout << "A = 0*B + 1*C\n";
		return true;
	}

	if (B == C)
	{
		std::cout << "B = 0*A + 1*C\n";
		return true;
	}

	double alpha;
	if (Utility::getInstance().isCollinear(A, B, C))
	{
		if (Raport(A, B, C, alpha))
		{
			std::cout << "B = " << 1 - alpha << " * A + " << alpha << " * C\n";
			return true;
		}
	}
	else
	{
		std::cout << "Puncte necoliniare\n";
		return true;
	}
	return false;
}

// Laboratorul 2
// Daca un patrulater e convex sau concav + Daca un punct M este in convex hull-ul patrulaterului
bool isConvex(GeomPolygon2D& polygon)
{
	GeomPolyline2D poly = polygon.getPolyline();
	std::vector<double> zComponent(poly.getNumberOfVertices());
	GeomPoint2D A, B, C;

	for (unsigned i = 0; i < zComponent.size(); i++)
	{
		if (i == zComponent.size() - 2)
		{
			poly.getVertexAt(i, A);
			poly.getVertexAt(i + 1, B);
			poly.getVertexAt(0, C);
		}
		if (i == zComponent.size() - 1)
		{
			poly.getVertexAt(i, A);
			poly.getVertexAt(0, B);
			poly.getVertexAt(1, C);
		}
		poly.getVertexAt(i, A);
		poly.getVertexAt(i + 1, B);
		poly.getVertexAt(i + 2, C);

		zComponent[i] = (B.getX() - A.getX()) * (C.getY() - B.getY()) - (B.getY() - A.getY()) * (C.getX() - B.getX());
	}
	for (unsigned i = 0; i < zComponent.size() - 1; i++)
	{
		if ((zComponent[i] >= 0 && zComponent[i + 1] < 0) || (zComponent[i] < 0 && zComponent[i + 1] >= 0))
		{
			return false;
		}
	}
	return true;
}
double TriangleAria(GeomPoint2D& A, GeomPoint2D& B, GeomPoint2D& C)
{
	double det;
	det = A.getX() * B.getY() +
		C.getX() * A.getY() +
		B.getX() * C.getY() -
		C.getX() * B.getY() -
		B.getX() * A.getY() -
		A.getX() * C.getY();
	return abs(det) / 2;
}
bool Laborator::Laborator2(GeomPolygon2D& polygon, GeomPoint2D& M)
{
	if (isConvex(polygon))
	{
		std::cout << "Poligon convex\n";
	}
	else
	{
		std::cout << "Poligon concav\n";
	}
	std::vector<GeomPoint2D> convexHull;
	Utility::getInstance().getConvexHull(convexHull, polygon.getPolyline());

	//Tratez cazul numai pentru 3 sau 4 puncte
	if (convexHull.size() == 3)
	{
		double mainArea = TriangleAria(convexHull[0], convexHull[1], convexHull[2]);

		if (mainArea == TriangleAria(convexHull[0], M, convexHull[1]) +
			TriangleAria(convexHull[1], M, convexHull[2]) +
			TriangleAria(convexHull[2], M, convexHull[0]))
		{
			std::cout << "Punctul M este in acoperirea convexa!\n";
		}
		else
		{
			std::cout << "Punctul M NU este in acoperirea convexa!\n";

		}
		return true;
	}
	if (convexHull.size() == 4)
	{
		double mainArea = TriangleAria(convexHull[0], convexHull[1], convexHull[2]);

		if (mainArea == TriangleAria(convexHull[0], M, convexHull[1]) +
			TriangleAria(convexHull[1], M, convexHull[2]) +
			TriangleAria(convexHull[2], M, convexHull[0]))
		{
			std::cout << "Punctul M este in acoperirea convexa!\n";
		}
		else
		{
			mainArea = TriangleAria(convexHull[2], convexHull[3], convexHull[0]);

			if (mainArea == TriangleAria(convexHull[2], M, convexHull[3]) +
				TriangleAria(convexHull[3], M, convexHull[0]) +
				TriangleAria(convexHull[0], M, convexHull[2]))
			{
				std::cout << "Punctul M este in acoperirea convexa!\n";
			}
			else
			{
				std::cout << "Punctul M NU este in acoperirea convexa!\n";
			}
		}
		return true;
	}
	std::cout << "Nu stiu sefu'!\n";
	return false;
}

// Laborator 3
// Intersectii de segmente 2D
bool Laborator::Laborator3(GeomPoint2D& A, GeomPoint2D& B, GeomPoint2D& C, GeomPoint2D& D)
{
	// scriem segmentul 1 ca A + direction
	// analog segementul 2 ca B + direction
	GeomSegment2D segment1(A, B);
	GeomSegment2D segment2(C, D);

	double t;	// finale pentru intersectie
	GeomVector2D directionA, directionC;
	directionA = segment1.getDirection();
	directionC = segment2.getDirection();

	double rxs = GeomVector2D().cross_product(directionA, directionC);
	double qpxr = GeomVector2D().cross_product(GeomVector2D(A, C), directionA);
	double qpxs = GeomVector2D().cross_product(GeomVector2D(A, C), directionC);
	if (rxs == 0)
	{
		if (qpxr == 0)
		{
			// Puncte collinerare si overlapping
			double t0 = (GeomVector2D().dot_product(GeomVector2D(A, C), directionA)) / (GeomVector2D().dot_product(directionA, directionA));
			double t1 = t0 + (GeomVector2D().dot_product(directionC, directionA)) / (GeomVector2D().dot_product(directionA, directionA));

			// Verificam intervalul t0, t1 cu intervalul [0,1]
			if (t0 < 0)
			{
				if (t1 < 0)
				{
					//  C??D     A----B
					std::cout << "Colineare, dar NU se intersecteaza\n";
					return true;
				}
				// C---A---D---B
				if ((t1 >= 0 && t1 < 1))
				{
					std::cout << A << "<--->" << D << "\n";
					return true;
				}
				// C---A---B---D
				if (t1 > 1)
				{
					std::cout << A << "<--->" << B << "\n";
					return true;
				}
			}
			if (t0 >= 0 && t0 <= 1)
			{
				// D---A---C---B
				if (t1 < 0)
				{
					std::cout << A << "<--->" << C << "\n";
					return true;
				}

				// A---D---C---B
				if (t1 >= 0 && t1 < t0)
				{
					std::cout << D << "<--->" << C << "\n";
					return true;
				}
				// A---C---D---B
				if (t1 > t0 && t1 <= 1)
				{
					std::cout << C << "<--->" << D << "\n";
					return true;
				}
				// A---C---B---D
				if (t1 > 1)
				{
					std::cout << C << "<--->" << B << "\n";
					return true;
				}
			}
			if (t0 > 1)
			{
				// D---A---B---C
				if (t1 < 0)
				{
					std::cout << A << "<--->" << B << "\n";
					return true;
				}
				// A---D---B---C
				if (t1 >= 0 && t1 <= 1)
				{
					std::cout << D << "<--->" << B << "\n";
					return true;
				}
				// A---B---D???C
				if (t1 > 1)
				{
					std::cout << "Colineara, dar NU se intersecteaza! \n";
					return true;
				}

			}
		}
		else
		{
			std::cout << "Paralele si nu se intersecteaza \n";
			return true;
		}
	}
	else
	{
		t = qpxs / rxs;

		//if ((t >= 0 && t <= 1) && (u >= 0 && u <= 1))
		if (t >= 0 && t <= 1)
		{
			GeomVector2D VectInt(A);
			VectInt += directionA * t;
			GeomPoint2D intersection(VectInt.getX(), VectInt.getY());
			std::cout << "Se intersecteaza in punctul :" << intersection << "\n";
			return true;
		}
		else
		{
			std::cout << "Segmente nu sunt paralele, dar NU se intersecteaza\n";
			return true;
		}
	}

	return false;
}

// Laborator 4
// 4 Puncte A,B,C daca formeaza un triunghi si D, unde se afla D fata ce cercul circumscris  ABC
// e ABCD (nu am cazuri degenerate) circumscriptibil?
bool Laborator::Laborator4(GeomPoint2D& A, GeomPoint2D& B, GeomPoint2D& C, GeomPoint2D& D)
{
	GeomPoint2D MidBC((B.getX() + C.getX()) / 2, (B.getY() + C.getY()) / 2);
	GeomPoint2D MidAB((A.getX() + B.getX()) / 2, (A.getY() + B.getY()) / 2);

	double perpSlopeAB = -(B.getX() - A.getX()) / (B.getY() - A.getY());
	double perpSlopeBC = -(C.getX() - B.getX()) / (C.getY() - B.getY());

	double CircumcenterX = ((perpSlopeBC * MidBC.getX()) + MidBC.getY()) - ((perpSlopeAB * MidAB.getX()) + MidAB.getY()) / (perpSlopeBC - perpSlopeAB);
	double CircumcenterY = perpSlopeAB * (CircumcenterX - MidAB.getX()) + MidAB.getY();

	GeomPoint2D Circumcenter = GeomPoint2D(CircumcenterX, CircumcenterY);
	double raza = Circumcenter.distanceTo(A);

	if (Circumcenter.distanceTo(D) < raza)
	{
		std::cout << " Punctul D se afla in cercul circumscris ABC!\n";
	}
	if (Circumcenter.distanceTo(D) == raza)
	{
		std::cout << " Punctul D se afla pe cercul circumscris ABC!\n";
	}
	if (Circumcenter.distanceTo(D) > raza)
	{
		std::cout << " Punctul D se afla in afara cercul circumscris ABC!\n";
	}

	if (A.distanceTo(B) + D.distanceTo(C) == A.distanceTo(C) + B.distanceTo(D))
	{
		std::cout << "ABCD e inscriptibil!\n";
		return true;
	}
	else
	{
		std::cout << "ABCD NU e inscriptibil!\n";
		return true;
	}
	return false;
}