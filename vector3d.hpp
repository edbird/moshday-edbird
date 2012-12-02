/**
 * Documentation:
 *
 * TODO: this
 *
 * Date: 2012-10-31
 *
 **/

#include <iostream>

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP


class vector3d
{
    public:
        // Constructor and Destructor
        vector3d();
        vector3d(const vector3d& other);
        vector3d(double x, double y, double z);
        virtual ~vector3d();

        // Assignment
        const vector3d& operator=(const vector3d& other);

        // Member Access
        //TODO: should have a const?
        double& operator[] (int index);
        double operator[] (int index) const;

        // Math Op - return other
        vector3d operator* (double factor) const;
        vector3d operator/ (double factor) const;

        vector3d operator+ (const vector3d& other) const;
        vector3d operator- (const vector3d& other) const;
        vector3d operator- () const;
        vector3d cross(const vector3d& other) const;
        double dot(const vector3d& other) const;

        // Math Op - modify self
        const vector3d& operator*= (double factor);
        const vector3d& operator/= (double factor);

        const vector3d& operator+= (const vector3d& other);
        const vector3d& operator-= (const vector3d& other);

        // Math - return other
        double mod() const;
        double modsq() const;
        vector3d normal() const;
        double normalize();

        // Get
        double x() { return v[0]; }
        double y() { return v[1]; }
        double z() { return v[2]; }
        double xyz(double& x, double& y, double& z){
            x = v[0];
            y = v[1];
            z = v[2];
            return v[0];
        }
        double xyz(double& y, double& z){
            y = v[1];
            z = v[2];
            return v[0];
        }
        // Set
        double sx (double val) { v[0] = val; return v[0]; }
        double sy (double val) { v[1] = val; return v[1]; }
        double sz (double val) { v[2] = val; return v[2]; }
        double sxyz(double x, double y, double z){
            v[0] = x;
            v[1] = y;
            v[2] = z;
            return v[0];
        }
        // Reset
        void reset() { v[0] = v[1] = v[2] = 0.0d; }

    protected:
    private:
        double v[3];
};

vector3d operator* (double scale, const vector3d& vec);
std::ostream& operator<< (std::ostream& out, const vector3d& vec);

#endif // vector3D_HPP
