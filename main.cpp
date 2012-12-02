
// All system stuff
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <GL/glut.h>

#include "soldier.hpp"
#include "team.hpp"
#include "battlefield.hpp"
#include "top-down-cam.hpp"

#include "main-global.cpp"


// All user stuff
#include "main.hpp" // Constant and Macro Definitions
//#include "main-cleanup.cpp" // Cleanup (free) function
//#include "main-init.cpp" // OpenGL init rendering
//#include "main-resize.cpp" // OpenGL glut window resize
//#include "main-draw.cpp" // OpenGL main drawing code
//#include "main-key.cpp" // OpenGL standard keypress handle
//#include "main-special.cpp" // OpenGL special keypress handle
//#include "main-timer.cpp" // OpenGL timer (screen refresh trigger) function


int main(int argc, char* argv[]){

    // Reset keyboard
    for(unsigned char i = 0; i < 0xff; i ++){
        keys[i] = 0;
    }

    // Exit function
    atexit(cleanup);

    // OpenGL
    glutInit(&argc, argv);
    initRendering();

    // OpenGL / glut callback functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyboard);
    glutKeyboardUpFunc(handleKeyboardUp);
    glutSpecialFunc(handleKeyboardSpecial);
    glutReshapeFunc(handleResize);
    glutIdleFunc(NULL);
    glutTimerFunc(ms_delay, handleTimer, 0); //TODO: what should the numbers be?

    /// Team and Player Stuff

    // Camera Stuff
    camera.set_centre_x(0.0d);
    camera.set_centre_y(0.0d);
    camera.set_width(400.0d);
    camera.set_w2h_ratio(1.0d);
    camera.set_cam_vel(200.0d / fps);
    //camera.set_height(100.0d);

    // Setup the Battlefield
    arena.setpos(-350.0d, -200.0d);
    arena.setsize(700.0d, 400.0d);

    soldier nextsoldier0 = soldier();
    soldier nextsoldier1 = soldier();
    nextsoldier0.color_red = 0.5d; nextsoldier0.color_green = 0.8d; nextsoldier0.color_blue = 0.0d;
    nextsoldier1.color_red = 0.8d; nextsoldier1.color_green = 0.5d; nextsoldier1.color_blue = 0.0d;
    nextsoldier0.m_ab_viewrange = 10.0;
    nextsoldier1.m_ab_viewrange = 10.0;
    nextsoldier0.giveObjective(0.0d, 0.0d, nextsoldier0.TRANSIT_TYPE_GUNRUN, nextsoldier0.OBJECTIVE_TYPE_JUSTMOVE);
    nextsoldier1.giveObjective(0.0d, 0.0d, nextsoldier1.TRANSIT_TYPE_GUNRUN, nextsoldier1.OBJECTIVE_TYPE_JUSTMOVE);
    // TODO: Random Soldiers
    for(unsigned int addsol = 0; addsol < 10; addsol ++){
        nextsoldier0.spos(-320.0d, -50.0d + 20.0d * addsol);
        nextsoldier1.spos(+320.0d, -60.0d + 20.0d * addsol);
        team0.addSoldier(nextsoldier0);
        team1.addSoldier(nextsoldier1);
        //team0.soldiers.at(addsol).spos(-320.0d, -50.0d + 20.0d * addsol);
        //team1.soldiers.at(addsol).spos(+320.0d, -60.0d + 20.0d * addsol);
    }
    /// Team and Player Stuff

    // Main loop
    glutMainLoop();

    return EXIT_SUCCESS;
}
