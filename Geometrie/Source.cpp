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
//	GeomPoint3D A(1, 1, 1);
//	GeomPoint3D B(1, 5, 1);
//	GeomPoint3D C(5, 1, 4);
//	if (!lab.Laborator1(A, B, C))
//	{
//		std::cout << "Eroare";
//	}
//	system("Pause");
//
//	//Lab2
//	GeomPolyline2D poly;
//	poly.append(GeomPoint2D(0, 0));
//	poly.append(GeomPoint2D(2, 0));
//	poly.append(GeomPoint2D(2, 2));
//	poly.append(GeomPoint2D(0, 2));
//	GeomPolygon2D polygon(poly);
//	lab.Laborator2(polygon, GeomPoint2D(1, 3));
//	system("Pause");
//
//	//Lab3
//	GeomPoint2D AA(-1, 1), BB(1, -1);
//	GeomPoint2D CC(-20, 0), DD(20, 0);
//	lab.Laborator3(AA, BB, CC, DD);
//	system("Pause");
//
//	//Lab4
//	GeomPoint2D AAA(0, 0), BBB(0, 2), CCC(2, 0);
//	GeomPoint2D DDD(2, 2);
//	lab.Laborator4(AAA, BBB, CCC, DDD);
//	system("Pause");
//
//
//	return 0;
//}