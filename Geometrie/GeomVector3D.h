#ifndef GEOMVECTOR3D_H
#define GEOMVECTOR3D_H
#include <iostream>

class GeomVector3D
{
public:
	GeomVector3D();
	
	GeomVector3D(double, double, double);
	
	GeomVector3D(const GeomVector3D&);
	
	// Writes the Vector v into the output stream in the format (x,y,z) 
	// So it can be used by various iostream functions.
	friend std::ostream &operator << (std::ostream&, const GeomVector3D&);
	
	// Compares the x, y and z components of Vector v1 and to the x, y 
	// And z components of Vector v2 and returns true if they are 
	// Identical. Otherwise, it returns false.
	friend bool operator == (const GeomVector3D&, const GeomVector3D&);
	
	// Compares the x, y and z components of GeomVector3D v1 and to the x, y 
	// And z components of GeomVector3D v2 and returns true if they are not 
	// Identical. Otherwise, it returns false.
	friend bool operator != (const GeomVector3D&, const GeomVector3D&);
	
	// Adds the x, y and z components of GeomVector3D v1 to the x, y and z 
	// compenents of GeomVector3D v2 and returns the result.
	friend GeomVector3D operator + (const GeomVector3D&, const GeomVector3D&);
	
	// Subtracts the x, y and z components of GeomVector3D v2 to the x, y and 
	// z compenents of GeomVector3D v1 and returns the result.
	friend GeomVector3D operator - (const GeomVector3D&, const GeomVector3D&);

	// Multiplies the x, y and z components of GeomVector3D v with a scalar 
	// value and returns the result.
	friend GeomVector3D operator * (const GeomVector3D&, double);
	friend GeomVector3D operator * (double, const GeomVector3D&);

	// Divides the x, y and z components of GeomVector3D v with a scalar 
	// value and returns the result.
	friend GeomVector3D operator / (const GeomVector3D&, double);
	friend GeomVector3D operator / (double, const GeomVector3D&);

	// Computes the dot product between GeomVector3D v1 and GeomVector3D v2 and 
	// returns the result.
	friend double DotProduct(const GeomVector3D&, const GeomVector3D&);

	// Computes the cross product between GeomVector3D v1 and this vector
	// returns the result.
	GeomVector3D CrossProduct(const GeomVector3D&);

	// Returns a GeomVector3D whos x, y and z components are the minimum 
	// components found in GeomVector3D v1 and GeomVector3D v2.
	friend GeomVector3D Min(const GeomVector3D&, const GeomVector3D&);
	
	
	// Returns a GeomVector3D whos x, y and z components are the maximum 
	// components found in GeomVector3D v1 and GeomVector3D v2.
	friend GeomVector3D Max(const GeomVector3D&, const GeomVector3D&);
	
	// Returns the scalar distance between the GeomVector3D v1 and the GeomVector3D 
	// v2.
	friend double DistanceBetween(const GeomVector3D&, const GeomVector3D&);
	
	// Returns the scalar squared distance between the GeomVector3D v1 and 
	// the GeomVector3D v2.
	friend double DistanceBetweenSquared(const GeomVector3D&, const GeomVector3D&);
	
	// Assigns this GeomVector3D's components to be equal to GeomVector3D v's 
	// components.
	GeomVector3D &operator = (const GeomVector3D&);
	
	// Adds to this GeomVector3D's components the components of GeomVector3D v.
	GeomVector3D &operator += (const GeomVector3D&);
	
	// Subtract from this GeomVector3D's components the components of GeomVector3D 
	// v.
	GeomVector3D &operator -= (const GeomVector3D&);
	
	// Multiply this GeomVector3D's components by a scalar value.
	
	GeomVector3D &operator *= (double);
	
	// Divide this GeomVector3D's components by a scalar value.
	GeomVector3D &operator /= (double);
	
	// Negate the components of this GeomVector3D.
	GeomVector3D &operator - ();
	
	// Allows access to the x, y and z components through an array 
	// subscript notation.
	double &operator [] (int);
	
	void MakeZero();
	
	// Returns true if the x, y and z components of this GeomVector3D are 
	// equal to zero.
	bool IsZero();
	
	// Returns the magnitude of the x, y and z components squared.
	double LengthSquared();
	
	// Returns the magnitude of the x, y and z components.
	double Length();
	
	// Sets the components of this GeomVector3D in such a way that their 
	// magnitude is equal to one.
	void Normalize();
	
	// Compares the magnitude of this GeomVector3D to one.
	bool IsNormalized();

	//Set Values
	void Set(double, double, double);

	double getX() const { return this->m_x; }
	double getY() const { return this->m_y; }
	double getZ() const { return this->m_z; }

private:
	double m_x;
	double m_y;
	double m_z;
};
#endif