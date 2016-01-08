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
//	GeomPolyline2D polyline;
//	polyline.append(GeomPoint2D(0, 0));
//	polyline.append(GeomPoint2D(1, 0));
//	polyline.append(GeomPoint2D(1, 1));
//	polyline.append(GeomPoint2D(0, 1));
//	GeomPolygon2D firtPolygon(polyline);
//
//	GeomPolyline2D secondPolyline;
//	secondPolyline.append(GeomPoint2D(5, 5));
//	secondPolyline.append(GeomPoint2D(6, 5));
//	secondPolyline.append(GeomPoint2D(6, 6));
//	secondPolyline.append(GeomPoint2D(5, 6));
//	GeomPolygon2D secondPolygon(secondPolyline);
//
//	Utility::getInstance().bigProject(firtPolygon, secondPolygon);
//
//	system("Pause");
//
//	return 0;
//}