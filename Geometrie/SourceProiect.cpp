#include <iostream>
#include <gl/freeglut.h>
#include <vector>
#include "Utility.h"
#include "GeomPoint3D.h"
#include "GeomPolyline3D.h"
#include "GeomPolyline2D.h"
#include "Laborator.h"

int WindowWidth = 900;
int WindowHeight = 700;

GeomPolygon2D firstPoly, secondPoly;
GeomPolyline2D convexHull;


void Init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, WindowWidth, 0, WindowHeight);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON); // Coordonatele varfurilor primului dreptunghi

	GeomPoint2D tempPoint;
	GeomPolyline2D tempPoly = firstPoly.getPolyline();
	for (auto i = 0; i < tempPoly.getNumberOfVertices(); i++)
	{
		tempPoly.getVertexAt(i, tempPoint);
		glVertex2i(tempPoint.getX(), tempPoint.getY());
	}
	glEnd();

	glBegin(GL_POLYGON); // Coordonatele varfurilor celui de-al doilea dreptunghi
	tempPoly = secondPoly.getPolyline();
	for (auto i = 0; i < tempPoly.getNumberOfVertices(); i++)
	{
		tempPoly.getVertexAt(i, tempPoint);
		glVertex2i(tempPoint.getX(), tempPoint.getY());
	}
	glEnd();
	
	glLineWidth(2.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON); // Coordonatele infasuratorii convexe
	for (auto i = 0; i < convexHull.getNumberOfVertices(); i++)
	{
		convexHull.getVertexAt(i, tempPoint);
		glVertex2i(tempPoint.getX(), tempPoint.getY());
	}
	glEnd();
	glFlush();
}

void ComputeConvexHull()
{
	GeomPolyline2D polyline;
	polyline.append(GeomPoint2D(100, 100));
	polyline.append(GeomPoint2D(300, 100));
	polyline.append(GeomPoint2D(300, 200));
	polyline.append(GeomPoint2D(100, 200));
	GeomPolygon2D firstPolygon(polyline);
	firstPoly = firstPolygon;

	GeomPolyline2D secondPolyline;
	secondPolyline.append(GeomPoint2D(500, 500));
	secondPolyline.append(GeomPoint2D(700, 500));
	secondPolyline.append(GeomPoint2D(700, 600));
	secondPolyline.append(GeomPoint2D(500, 600));
	GeomPolygon2D secondPolygon(secondPolyline);
	secondPoly = secondPolygon;

	Utility::getInstance().bigProject(firstPolygon, secondPolygon, convexHull);

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("Infasuratoare");
	Init();
	ComputeConvexHull();
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}