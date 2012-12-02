
/** THIS DEFINE SWITCH CHANGES THE COMPILE MODE **/
/* 
 * To compile as a static library:
 * #define __COMPILE_MODE__ __COMPILE_MODE__LIB__
 * 
 * To compile as part of a project:
 * #define __COMPILE_MODE__ __COMPILE_MODE__NORMAL__
 * 
 */

#define __COMPILE_MODE__LIB__ 0
#define __COMPILE_MODE__NORMAL__ 1
#define __COMPILE_MODE__ __COMPILE_MODE__LIB__

#if __COMPILE_MODE__
  #include "main.h"
#else
  /* Physics */
  const double C = 2.997924850E+8;
  const double Csquared = 8.9875534E+16;
  const double G = 6.673E-11;
  const double PI = 3.14159265359;
  // Boolean Definitions
  const int INT_FALSE = 0x0;
  const int INT_TRUE = 0x1;
  // Integer Exit Codes
  const int INT_EXIT_SUCCESS = 0x0;
  const int INT_EXIT_FAILURE = 0x1;
  const int INT_GL_DRAWING_SUCCESS = 0x100;
  const int INT_GL_DRAWING_FAILURE = 0x101;
  const int INT_GL_DRAWING_NOTHING_TO_DRAW = 0x102;
#endif

#include <cmath>
#include "camera.h"

//TODO: remove
#include <iostream>

/// Consructor
camera_class::camera_class()
{
    _rotx = 0; _roty = 0; _rotz = 0;
    _posx = 0; _posy = 0; _posz = 0;
    _cenx = 0; _ceny = 0; _cenz = 0;
    _eyex = 0; _eyey = 0; _eyez = 0;
     _upx = 0;  _upy = 0;  _upz = 0;

    _rotation_mode = __INT__rotation_mode_degrees;

    resetrxyz();
}
/// Destructor
camera_class::~camera_class()
{
    //dtor
}
/// Copy Constructor
camera_class::camera_class(const camera_class& other) //TODO: this
{
    _rotx = other._rotx;    _roty = other._roty;    _rotz = other._rotz;
    _posx = other._posx;    _posy = other._posy;    _posz = other._posz;
    _cenx = other._cenx;    _ceny = other._ceny;    _cenz = other._cenz;
    _eyex = other._eyex;    _eyey = other._eyey;    _eyez = other._eyez;
     _upx = other. _upx;     _upy = other. _upy;     _upz = other. _upz;

    _rotation_mode = other._rotation_mode;
}
/// Assignment Operator
camera_class& camera_class::operator=(const camera_class& rhs) //TODO: this
{
    if (this == &rhs) return *this; // handle self assignment

    _rotx = rhs._rotx;    _roty = rhs._roty;    _rotz = rhs._rotz;
    _posx = rhs._posx;    _posy = rhs._posy;    _posz = rhs._posz;
    _cenx = rhs._cenx;    _ceny = rhs._ceny;    _cenz = rhs._cenz;
    _eyex = rhs._eyex;    _eyey = rhs._eyey;    _eyez = rhs._eyez;
     _upx = rhs. _upx;     _upy = rhs. _upy;     _upz = rhs. _upz;

    _rotation_mode = rhs._rotation_mode;

    return *this;
}

/// Get Rotation
GLdouble camera_class::rx()
{
    return _rotx;
}
GLdouble camera_class::ry()
{
    return _roty;
}
GLdouble camera_class::rz()
{
    return _rotz;
}
GLdouble camera_class::rxyz(double& valx, double& valy, double& valz)
{
    valx = _rotx;
    valy = _roty;
    valz = _rotz;
    return _rotx;
}
GLdouble camera_class::rzxy(double& valx, double& valy)
{
    valx = _rotx;
    valy = _roty;
    return _rotz;
}
/// Get Position
GLdouble camera_class::px()
{
    return _posx;
}
GLdouble camera_class::py()
{
    return _posy;
}
GLdouble camera_class::pz()
{
    return _posz;
}
GLdouble camera_class::pxyz(double& valx, double& valy, double& valz)
{
    valx = _posx;
    valy = _posy;
    valz = _posz;
    return _posx;
}
GLdouble camera_class::pzxy(double& valx, double& valy)
{
    valx = _posx;
    valy = _posy;
    return _posz;
}
/// Get Center
GLdouble camera_class::cx()
{
    return _cenx;
}
GLdouble camera_class::cy()
{
    return _cenx;
}
GLdouble camera_class::cz()
{
    return _cenz;
}
GLdouble camera_class::cxyz(double& valx, double& valy, double& valz)
{
    valx = _cenx;
    valy = _ceny;
    valz = _cenz;
    return _cenx;
}
GLdouble camera_class::czxy(double& valx, double& valy)
{
    valx = _cenx;
    valy = _ceny;
    return _cenz;
}
/// Get Up Vector
GLdouble camera_class::ux()
{
    return _upx;
}
GLdouble camera_class::uy()
{
    return _upy;
}
GLdouble camera_class::uz()
{
    return _upz;
}
GLdouble camera_class::uxyz(double& valx, double& valy, double& valz)
{
    valx = _upx;
    valy = _upy;
    valz = _upz;
    return _upx;
}
GLdouble camera_class::uzxy(double& valx, double& valy)
{
    valx = _upx;
    valy = _upy;
    return _upz;
}

/// Set Rotation
GLdouble camera_class::srx(GLdouble arg)
{
    _rotx = arg;
    applyrxyz();
    return _rotx;
}
GLdouble camera_class::sry(GLdouble arg)
{
    _roty = arg;
    applyrxyz();
    return _roty;
}
GLdouble camera_class::srz(GLdouble arg)
{
    _rotz = arg;
    applyrxyz();
    return _rotz;
}
GLdouble camera_class::srxyz(double valx, double valy, double valz)
{
    _rotx = valx;
    _roty = valy;
    _rotz = valz;
    applyrxyz();
    return _rotx;
}
/// Set Position
GLdouble camera_class::spx(GLdouble arg) //TODO: return INT
{
    if(arg == _cenx && _posy == _cenx && _posz == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _posx = arg;
    _eyex = _posx;
    return _posx;
}
GLdouble camera_class::spy(GLdouble arg)
{
    if(_posx == _cenx && arg == _cenx && _posz == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _posy = arg;
    _eyey = _posy;
    return _posy;
}
GLdouble camera_class::spz(GLdouble arg)
{
    if(_posx == _cenx && _posy == _cenx && arg == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _posz = arg;
    _eyez = _posz;
    return _posz;
}
GLdouble camera_class::spxyz(double valx, double valy, double valz)
{
    if(valx == _cenx && valy == _cenx && valz == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _posx = valx;
    _posy = valy;
    _posz = valz;
    _eyex = _posx;
    _eyey = _posy;
    _eyez = _posz;
    return _posx;
}
/// Set Center
GLdouble camera_class::scx(GLdouble arg)
{
    if(_posx == arg && _posy == _cenx && _posz == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _cenx = arg;
    return _cenx;
}
GLdouble camera_class::scy(GLdouble arg)
{
    if(_posx == _cenx && _posy == arg && _posz == _cenz) return INT_EXIT_FAILURE; //TODO: throw exception

    _ceny = arg;
    return _cenx;
}
GLdouble camera_class::scz(GLdouble arg)
{
    if(_posx == _cenx && _posy == _cenx && _posz == arg) return INT_EXIT_FAILURE; //TODO: throw exception

    _cenz = arg;
    return _cenz;
}
GLdouble camera_class::scxyz(double valx, double valy, double valz)
{
    if(valx == _posx && valy == _posy && valz == _posz) return INT_EXIT_FAILURE; //TODO: throw exception

    _cenx = valx;
    _ceny = valy;
    _cenz = valz;
    return _cenx;
}
/// Set Up Vector
GLdouble camera_class::sux(GLdouble arg) //TODO: exception catches as above
{
    _upx = arg;
    normalizeuxyz();
    return _upx;
}
GLdouble camera_class::suy(GLdouble arg)
{
    _upy = arg;
    normalizeuxyz();
    return _upy;
}
GLdouble camera_class::suz(GLdouble arg)
{
    _upz = arg;
    normalizeuxyz();
    return _upz;
}
GLdouble camera_class::suxyz(double valx, double valy, double valz)
{
    _upx = valx;
    _upy = valy;
    _upz = valz;
    normalizeuxyz();
    return _upx;
}

int camera_class::applyrxyz()
{
    // Convert to correct angle measure
    if(_rotation_mode == __INT__rotation_mode_degrees){
        _rotx *= (PI / 180);
        _roty *= (PI / 180);
        _rotz *= (PI / 180);
    }
        // Do nothing if in radians

    // Apply Rotation Matrix
    /*
    _upx = (cos(_roty)*cos(_rotz))*_upx +
           (-cos(_rotx)*sin(_rotz) + sin(_rotx)*sin(_roty)*cos(_rotz))*_upy +
           (sin(_roty)*sin(_rotz) + cos(_rotx)*sin(_roty)*cos(_rotz))*_upz;
    _upy = (cos(_roty)*sin(_rotz))*_upx +
           (cos(_rotx)*cos(_rotz) + sin(_rotx)*sin(_roty)*sin(_rotz))*_upy +
           (-sin(_rotx)*cos(_rotz) + cos(_rotx)*sin(_roty)*sin(_rotz))*_upz;
    _upz = (-sin(_roty))*_upx +
           (sin(_rotx)*cos(_roty))*_upy +
           (cos(_rotx)*cos(_roty))*_upz;
           */
    /*
    double c = cos(_roty);
    double s = sin(_roty);
    double t = 1 - cos(_roty);
std::cout << c << " " << s << " " << t << "\n";

    double X = 1;
    double Y = 1;
    double Z = 1;

    _upx *= ((t*X*X + c) + (t*X*Y + s*Z) + (t*X*Z - s*Y));
    _upy *= ((t*X*Y - s*Z) + (t*Y*Y + c) + (t*Y*Z + s*X));
    _upz *= ((t*X*Z + s*Y) + (t*Y*Z - s*X) + (t*Z*Z + c));
            */

    double c = cos(_rotx);
    double s = sin(_rotx);
    _upx += _upx * (1);
    _upy += _upy * (c*_upy - s*_upz);
    _upz += _upz * (s*_upy + c*_upz);

    c = cos(_roty);
    s = sin(_roty);
    _upx += _upx * (c*_upx + s*_upz);
    _upy += _upy * (1);
    _upz += _upz * (-s*_upx + c*_upz);

    c = cos(_rotz);
    s = sin(_rotz);
    _upx += _upx * (c*_upx - s*_upy);
    _upy += _upy * (s*_upx + c*_upy);
    _upz += _upz * (1);



std::cout << _upx << " " << _upy << " " << _upz << "\n";





    // Delete the values in the rotation to prevent accidental rotating
    _rotx = _roty = _rotz = 0.0f;
    normalizeuxyz();
}


int camera_class::set_angle_mode_radians()
{
    _rotation_mode = __INT__rotation_mode_radians;
    return _rotation_mode;
}
int camera_class::set_angle_mode_degrees()
{
    _rotation_mode = __INT__rotation_mode_degrees;
    return _rotation_mode;
}
int camera_class::set_angle_mode(int arg)
{
    switch(arg){
        case __INT__rotation_mode_degrees:
        case __INT__rotation_mode_radians:
            // If okay argument, set the mode value
            _rotation_mode = arg;
        default:
            // Regardless, we return the current rotation mode
            return _rotation_mode;
    }
}
int camera_class::get_angle_mode()
{
    return _rotation_mode;
}

int camera_class::resetrxyz()
{
    _upx = 0.0f;
    _upy = 1.0f;
    _upz = 0.0f;
    normalizeuxyz();
    return INT_EXIT_SUCCESS;
}

double camera_class::normalizeuxyz()
{
    double __mod = sqrt(pow(_upx, 2) + pow(_upy, 2) + pow(_upz, 2));
    _upx /= __mod;
    _upy /= __mod;
    _upz /= __mod;
    __mod = sqrt(pow(_upx, 2) + pow(_upy, 2) + pow(_upz, 2));

    return __mod;
}

/// Returning the static, default camera object.
camera_class& glcam()
{
   static camera_class glcam_default = camera_class();
   return glcam_default;
}

