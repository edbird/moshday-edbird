#include <cmath>
#include <GL/glut.h>

#include "myOpenGLDrawingMethods.hpp"


void drawMyCircle(double radius, double x, double y)
{
    glBegin(GL_POLYGON);
    for(unsigned int i = 0; i <= 360; i ++){
        double degInRad = i * DEG2RAD;
        glVertex2d(x + cos(degInRad) * radius, y + sin(degInRad) * radius);
    }
    glEnd();
}
