#include <GL/glut.h>

#include "top-down-cam.hpp"


void handleResize(int w, int h){

    // Set viewport (gl drawing surface inside window manager)
    glViewport(0, 0, w, h);

    // Set Camera w2h ratio
    //glutReshapeWindow(1024, 768);
    camera.set_w2h_ratio((double)h / (double)w);

    // Set matrix mode back again
    glMatrixMode(GL_PROJECTION);
    // Reset matrix stack
    glLoadIdentity();
    // Set drawing surface propeties
    ///gluPerspective(45.0, (double)w / (double)h, 1.0d, 100.0d);
    //glOrtho(-w/2, w/2, -h/2, h/2, -10.0d, 10.0d);
    glOrtho(camera.left(), camera.right(), camera.bottom(), camera.top(), camera.near(), camera.far());
    // Put matrix mode back
    glMatrixMode(GL_MODELVIEW);
}

