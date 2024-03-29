

#include <GL/glut.h>

#include "main-global.cpp"

#include "collect.hpp"
#include "battlefield.hpp"
#include "top-down-cam.hpp"


void drawScene(){

    // Clear screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 2d stuff:
        // Set matrix mode back again
        glMatrixMode(GL_PROJECTION);
        // Reset matrix stack
        glLoadIdentity();
        // Set drawing surface propeties
        glOrtho(camera.left(), camera.right(), camera.bottom(), camera.top(), camera.near(), camera.far());
    // end of 2d


    glMatrixMode(GL_MODELVIEW);

    // Lighting

    // Camera
    glLoadIdentity();
    gluLookAt(0.0d, 0.0d, -1.0d,
              0.0d, 0.0d, 0.0d,
              0.0d, 1.0d, 0.0d);


    /// Drawing Code goes here

    // Draw reference axis
    glColor3d(1.0d, 0.0d, 0.0d);
    glBegin(GL_LINES);
        glVertex3d(-0.0d, 0.d, 0.5d);
        glVertex3d(+300.0d, 0.d, 0.5d);
    glEnd();

    glColor3d(0.0d, 1.0d, 0.0d);
    glBegin(GL_LINES);
        glVertex3d(0.d, -0.0d, 0.5d);
        glVertex3d(0.d, +300.0d, 0.5d);
    glEnd();

    // Battlefield stuff
    for(unsigned int s = 0; s < global.narenasections(); s ++){
        global.arenasections().at(s).draw();
    }

    /// Soldier Stuff
    for(unsigned int s = 0; s < global.nsoldiers(); s ++){
        global.soldiers().at(s).draw();
    }



    // End of drawing


    // Swap screen buffer
    glutSwapBuffers();
}


