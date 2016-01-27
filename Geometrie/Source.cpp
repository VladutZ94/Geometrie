//#include <vector>
//#include <iostream>
//#include "Utility.h"
//#include "GeomPoint3D.h"
//#include "GeomPolyline3D.h"
//#include "GeomPolyline2D.h"
//#include "Laborator.h"
//
//
//int main()
//{
//	Laborator lab;
//	//Lab1
//	std::cout << "Laborator 1\n";
//	GeomPoint3D A(1, 1, 1);
//	GeomPoint3D B(1, 3, 5);
//	GeomPoint3D C(1, 1, 1);
//	if (!lab.Laborator1(A, B, C))
//	{
//		std::cout << "Eroare";
//	}
//	system("Pause");
//
//	//Lab2
//	std::cout << "\n\nLaborator 2\n";
//	GeomPolyline2D poly;
//	poly.append(GeomPoint2D(0, 0));
//	poly.append(GeomPoint2D(2, 2));
//	poly.append(GeomPoint2D(4, 0));
//	poly.append(GeomPoint2D(2, 4));
//	GeomPolygon2D polygon(poly);
//	lab.Laborator2(polygon, GeomPoint2D(2, 5));
//	system("Pause");
//
//	//Lab3
//	std::cout << "\n\nLaborator 3\n";
//	GeomPoint2D AA(0, 0), BB(2, 2);
//	GeomPoint2D CC(1, 1), DD(3, 3);
//	lab.Laborator3(AA, BB, CC, DD);
//	system("Pause");
//
//	//Lab4
//	std::cout << "\n\nLaborator 3\n";
//	GeomPoint2D AAA(0, 0), BBB(0, 2), CCC(2, 0);
//	GeomPoint2D DDD(2, 2);
//	lab.Laborator4(AAA, BBB, CCC, DDD);
//	system("Pause");
//
//
//	return 0;
//}