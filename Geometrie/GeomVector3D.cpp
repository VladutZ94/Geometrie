#include "GeomVector3D.h"
#include <assert.h>
#include <math.h>

GeomVector3D::GeomVector3D()
{
	m_x = 0.0;
	m_y = 0.0;
	m_z = 0.0;
}

GeomVector3D::GeomVector3D(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

GeomVector3D::GeomVector3D(const GeomVector3D &v)
{
	this->m_x = v.m_x;
	this->m_y = v.m_y;
	this->m_z = v.m_z;
}

std::ostream &operator<<(std::ostream &os, const GeomVector3D &v)
{
	os << '(' << v.m_x << ',' << v.m_y << ',' << v.m_z << ')';
	return os;
}

bool operator==(const GeomVector3D &v1, const GeomVector3D &v2)
{
	return ((v1.getX() == v2.getX()) && (v1.getY() == v2.getY()) && (v1.getZ() ==  v2.getZ()));
}

bool operator!=(const GeomVector3D &v1, const GeomVector3D &v2)
{
	return (!(v1.m_x == v2.m_x) || !(v1.m_y == v2.m_y) || !(v1.m_z == v2.m_z));
}

GeomVector3D operator+(const GeomVector3D &v1, const GeomVector3D &v2)
{
	return GeomVector3D(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

GeomVector3D operator-(const GeomVector3D &v1, const GeomVector3D &v2)
{
	return GeomVector3D(v1.getX() - v2.getX(), v1.getY() - v2.getY(), v1.getZ() - v2.getZ());
}

GeomVector3D operator*(const GeomVector3D &v, double scalar)
{
	return GeomVector3D(v.getX()*scalar, v.getY()*scalar, v.getZ()*scalar);
}

GeomVector3D operator*(double scalar, const GeomVector3D &v)
{
	return GeomVector3D(v.getX()*scalar, v.getY()*scalar, v.getZ()*scalar);
}

GeomVector3D operator/(const GeomVector3D &v, double scalar)
{
	assert(!(scalar == 0));
	scalar = 1.0 / scalar;
	return GeomVector3D(v.getX()*scalar, v.getY()*scalar, v.getZ()*scalar);
}

GeomVector3D operator/(double scalar, const GeomVector3D &v)
{
	assert(!(scalar == 0));
	scalar = 1.0 / scalar;
	return GeomVector3D(v.getX()*scalar, v.getY()*scalar, v.getZ()*scalar);
}

double DotProduct(const GeomVector3D &v1, const GeomVector3D &v2)
{
	return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}

GeomVector3D GeomVector3D::CrossProduct(const GeomVector3D &v1)
{
	return GeomVector3D(v1.getY()* this->getZ() - v1.getZ()* this->getY(),
		v1.getZ()* this->getX() - v1.getX()* this->getZ(),
		v1.getX()* this->getY() - v1.getY()* this->getX());
}

double DistanceBetween(const GeomVector3D &v1, const GeomVector3D &v2)
{
	GeomVector3D distance = v1 - v2;
	return distance.Length();
}

double DistanceBetweenSquared(const GeomVector3D &v1, const GeomVector3D &v2)
{
	GeomVector3D distance = v1 - v2;
	return distance.LengthSquared();
}

GeomVector3D &GeomVector3D::operator=(const GeomVector3D &v)
{
	this->m_x = v.getX();
	this->m_y = v.getY();
	this->m_z = v.getZ();
	return *this;
}

GeomVector3D &GeomVector3D::operator+=(const GeomVector3D &v)
{
	this->m_x += v.getX();
	this->m_y += v.getY();
	this->m_z += v.getZ();
	return *this;
}

GeomVector3D &GeomVector3D::operator-=(const GeomVector3D &v)
{
	this->m_x -= v.getX();
	this->m_y -= v.getY();
	this->m_z -= v.getZ();
	return *this;
}

GeomVector3D &GeomVector3D::operator*=(double scalar)
{
	this->m_x *= scalar;
	this->m_y *= scalar;
	this->m_z *= scalar;
	return *this;
}

GeomVector3D &GeomVector3D::operator/=(double scalar)
{
	assert(!(scalar == 0));
	scalar = 1.0f / scalar;
	this->m_x *= scalar;
	this->m_y *= scalar;
	this->m_z *= scalar;
	return *this;
}

GeomVector3D &GeomVector3D::operator-()
{
	this->m_x = -this->m_x;
	this->m_y = -this->m_y;
	this->m_z = -this->m_z;
	return *this;
}

void GeomVector3D::Set(double x, double y, double z)
{
	this->m_x = x;
	this->m_y = y;
	this->m_z = z;
}

void GeomVector3D::MakeZero()
{
	this->m_x = this->m_y = this->m_z = 0.0f;
}

bool GeomVector3D::IsZero()
{
	return this->m_x == 0 && this->m_y == 0 && this->m_z == 0;
}

double GeomVector3D::LengthSquared()
{
	return this->m_x*this->m_x + this->m_y*this->m_y + this->m_z*this->m_z;
}

double GeomVector3D::Length()
{
	return sqrt(LengthSquared());
}

void GeomVector3D::Normalize()
{
	double magnitude = Length();
	assert(!(magnitude == 0));

	magnitude = 1.0f / magnitude;

	this->m_x *= magnitude;
	this->m_y *= magnitude;
	this->m_z *= magnitude;
}

bool GeomVector3D::IsNormalized()
{
	return Length() == 1.0;
}
