#include <vector>
#include <iostream>
#include "Utility.h"
#include "GeomPoint3D.h"
#include "GeomPolyline3D.h"

//Main-ul pentru laboratorul 1

int main()
{
	//Lab 1 puncte coliniare
	GeomPoint3D A(1, 1, 1);
	GeomPoint3D C(1, 1, 5);
	GeomPoint3D B(1, 1, 9);
	double alpha;

	if (Utility::getInstance().isCollinear(A, B, C, alpha))
	{
		std::cout << "A" << A << "\n";
		std::cout << "B" << B << "\n";
		std::cout << "C" << C << "\n";

		system("pause");
	}
	else
	{
		std::cout << "Azi nu, mai incearca! \n";
		system("pause");
	}

	if (alpha == -1)
	{
		std::cout << "B = 1 * C + 0 * A;\n";
	}
	else
	{
		std::cout << "B = " << alpha << " * A + " << 1 - alpha << " * C;\n";
	}
	system("pause");
	return 0;
}

// Main-ul pentru laboratorul 2

//int main()
//{
//	GeomPolyline2D polyline;
//	std::vector<GeomPoint2D> vec;
//	vec.push_back(GeomPoint2D(1, 1));
//	vec.push_back(GeomPoint2D(2, 3));
//	vec.push_back(GeomPoint2D(3, 1));
//	vec.push_back(GeomPoint2D(2, 2));
//
//	//vec.push_back(GeomPoint2D(1, 1));
//	//vec.push_back(GeomPoint2D(1, 0));
//	//vec.push_back(GeomPoint2D(0, 0));
//	//vec.push_back(GeomPoint2D(0, 1));
//	//poly.setClosed();
//
//	GeomPolyline2D polygon(vec);
//
//	if (Utility::getInstance().getConvexHull(polygon.getVertices(), polyline))
//	{
//		std::cout << polygon;
//		if (Utility::getInstance().isPolygonConvex(polygon))
//		{
//			std::cout << "\nESTE Convex \n";
//		}
//		else
//		{
//			std::cout << "\nESTE Concav \n";
//		}
//
//		GeomPoint2D point(2, 16);
//		std::cout << polyline << "\n";
//		if (polyline.isInside(point))
//		{
//			std::cout << "\nPunctul " << point << " este in infasuratoarea convex a poligon.\n";
//		}
//		else
//		{
//			std::cout << "\nPunctul " << point << " nu este in infasuratoarea convex a poligon.\n";
//		}
//	}
//	system("Pause");
//	return 0;
//}