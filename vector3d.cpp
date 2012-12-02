
#include <cmath>

#include "vector3d.hpp"


/// Constructor
vector3d::vector3d()
{
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
}
//
vector3d::vector3d(double x, double y, double z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
}
//
vector3d::vector3d(const vector3d& other)
{
    ///copy ctor - think "push_back"
    v[0] = other.v[0];
    v[1] = other.v[1];
    v[2] = other.v[2];
}


/// Destructor
vector3d::~vector3d()
{

}


/// Assignment
const vector3d& vector3d::operator= (const vector3d& other)
{
    v[0] = other.v[0];
    v[1] = other.v[1];
    v[2] = other.v[2];
    return *this;
}


/// Access Operator
double& vector3d::operator[] (int index)
{
    return v[index];
}
//
double vector3d::operator[] (int index) const
{
    return v[index];
}


/// Math Op - return other
vector3d vector3d::operator* (double factor) const
{
    return vector3d(v[0] * factor, v[1] * factor, v[2] * factor);
}
//
vector3d vector3d::operator/ (double factor) const
{
    return vector3d(v[0] / factor, v[1] / factor, v[2] / factor);
}
//
vector3d vector3d::operator+ (const vector3d &other) const
{
    return vector3d(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
}
//
vector3d vector3d::operator- (const vector3d &other) const
{
    return vector3d(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
}
//
vector3d vector3d::operator- () const
{
    return vector3d(-v[0], -v[1], -v[2]);
}
//
vector3d vector3d::cross(const vector3d& other) const
{
    return vector3d(v[1] * other.v[2] - v[2] * other.v[1],
                       v[2] * other.v[0] - v[0] * other.v[2],
                       v[0] * other.v[1] - v[1] * other.v[0]);
}
//
double vector3d::dot(const vector3d& other) const
{
    return v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2];
}


/// Math Op - modify self
const vector3d& vector3d::operator*= (double factor)
{
    v[0] *= factor;
    v[1] *= factor;
    v[2] *= factor;
    return *this;
}
//
const vector3d& vector3d::operator/= (double factor)
{
    v[0] /= factor;
    v[1] /= factor;
    v[2] /= factor;
    return *this;
}
//
const vector3d& vector3d::operator+= (const vector3d& other)
{
    v[0] += other.v[0];
    v[1] += other.v[1];
    v[2] += other.v[2];
    return *this;
}
//
const vector3d& vector3d::operator-= (const vector3d& other)
{
    v[0] -= other.v[0];
    v[1] -= other.v[1];
    v[2] -= other.v[2];
    return *this;
}


/// Other Method
double vector3d::mod() const
{
    return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}
//
double vector3d::modsq() const
{
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}
//
double vector3d::normalize()
{
    double m = mod();
    v[0] /= m;
    v[1] /= m;
    v[2] /= m;
}
//
vector3d vector3d::normal() const
{
    double m = mod();
    return vector3d(v[0] / m, v[1] / m, v[2] / m);
}



/// Other Operator
vector3d operator* (double factor, const vector3d& vec)
{
    return vec * factor;
}

std::ostream& operator<< (std::ostream& output, const vector3d& vec)
{
	std::cout << '(' << vec[0] << ", " << vec[1] << ", " << vec[2] << ')';
	return output;
}

