#include <GL/glut.h>

void initRendering(){

    // Glut Window Manager stuff
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("<title>");

    // Enable openGL stuff
    //glEnable(GL_DEPTH_TEST
    //         | GL_COLOR_MATERIAL
    //         | GL_LIGHTING
    //         | GL_LIGHT0
    //         | GL_NORMALIZE);
    // Turn off lighting
    //glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    // Enable shade model
    glShadeModel(GL_SMOOTH);

    // Set clear color
    glClearColor(0.0d, 0.0d, 0.0d, 1.0d);
}

