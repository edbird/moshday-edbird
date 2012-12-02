
/*
 *
 *  Camera Class - Hold and manipulate camera variables.
 *
 *  _rot? ( r? ) - Camera rotation:                  ? = {x,y,z}
 *  _pos? ( p? ) - Camera position:                  ? = {x,y,z}
 *  _cen? ( c? ) - Camera view center:               ? = {x,y,z}
 *  _eye? ( -- ) - Camera position: (Same as _pos?): ? = {x,y,z}
 *   _up? ( u? ) - Camera up vector:                 ? = {x,y,z}
 *
 *  Note that eye and pos are exactly the same. Eye variables don't do anything,
 *  and they cannot be set or modified.
 *
 *  There are two types of method, a getter and a setter.
 *  The standard getter methods return the value as usual.
 *  The advanced getter methods also set the values of references passed as
 *  arguments to the function.
 *
 *  The position of the camera is set using sp?. : ? = {x,y,z}
 *  The rotation of the camera can be set using su?. : ? = {x,y,z} This
 *  specifies the "up" vector for the camera.
 *  The rotation can also be set using the sr?. : ? = {x,y,z}
 *  Using this requires a call to applyrxyz() to rotate the camera's 'up'
 *  vector.
 *  Use resetrxyz() to reset the camera's 'up' vector.
 *  The center of the screen, the point at which the camera points, is set using
 *  sc?. : ? = {x,y,z}
 *
 *
 */

#include <GL/glut.h>

#ifndef CAMERA_CLASS_HPP
#define CAMERA_CLASS_HPP

const char __INT__rotation_mode_degrees = 0x0;
const char __INT__rotation_mode_radians = 0x1;

class camera_class
{
    public:
        // Constructor & Destructor
        camera_class();
        virtual ~camera_class();

        // Copy & Assignment Operators
        camera_class(const camera_class& other);
        camera_class& operator=(const camera_class& other);

        // Get
        GLdouble rx(); GLdouble ry(); GLdouble rz();
        GLdouble px(); GLdouble py(); GLdouble pz();
        GLdouble cx(); GLdouble cy(); GLdouble cz();
        GLdouble ux(); GLdouble uy(); GLdouble uz();

        GLdouble rxyz(double& valx, double& valy, double& valz);
        GLdouble pxyz(double& valx, double& valy, double& valz);
        GLdouble cxyz(double& valx, double& valy, double& valz);
        GLdouble uxyz(double& valx, double& valy, double& valz);

        GLdouble rzxy(double& valx, double& valy);
        GLdouble pzxy(double& valx, double& valy);
        GLdouble czxy(double& valx, double& valy);
        GLdouble uzxy(double& valx, double& valy);

        // Set
        GLdouble srx(const double val); GLdouble sry(const double val); GLdouble srz(const double val); //TODO: const
        GLdouble spx(double val); GLdouble spy(double val); GLdouble spz(double val);
        GLdouble scx(double val); GLdouble scy(double val); GLdouble scz(double val);
        GLdouble sux(double val); GLdouble suy(double val); GLdouble suz(double val);

        GLdouble srxyz(double valx, double valy, double valz);
        GLdouble spxyz(double valx, double valy, double valz);
        GLdouble scxyz(double valx, double valy, double valz);
        GLdouble suxyz(double valx, double valy, double valz);

        // Methods
        int set_angle_mode_radians();
        int set_angle_mode_degrees();
        int set_angle_mode(int arg);
        int get_angle_mode();
        int resetrxyz();
        /** Reset the rotation so that _upx = 0.0f, _upy = 1.0f, _upz = 0.0f; **/
    private:
        // Variables - Camera Translation
        GLdouble _rotx; GLdouble _roty; GLdouble _rotz;
        GLdouble _posx; GLdouble _posy; GLdouble _posz;

        // Variables - "look at" Position
        GLdouble _cenx; GLdouble _ceny; GLdouble _cenz;
        GLdouble _eyex; GLdouble _eyey; GLdouble _eyez;
        GLdouble  _upx; GLdouble  _upy; GLdouble  _upz;

        char _rotation_mode;

        // Methods
        double normalizeuxyz();
        int applyrxyz();
        /** Take the degree values in _rotx, _roty, _rotz and convert to radians.
          * Apply the rotation to the  _upx,  _upy,  _upz values.
          * Set _rotx, roty, rotz to 0.0f.
          */
};

camera_class& glcam();

#endif // CAMERA_CLASS_HPP

