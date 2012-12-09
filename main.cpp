
// All system stuff
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <GL/glut.h>

#include "soldier.hpp"
#include "collect.hpp"
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
    camera.set_centre_x(350.0d);
    camera.set_centre_y(250.0d);
    camera.set_width(4*200.0d);
    camera.set_w2h_ratio(1.0d);
    camera.set_cam_vel(4*200.0d / fps);

    // Create Teams
    global.addTeams(2);

    // Setup the Battlefield
    global.addArenaSection(0.0d, 0.0d, 700.0d, 500.0d);
    global.setArenaSectionState(0, AREA_TYPE_NEUTRAL);
    global.addArenaSection(battlefield(50.0d, 50.0d, 100.0d, 400.0d));
    global.setArenaSectionState(1, AREA_TYPE_BASE);
    global.addArenaSection(battlefield(600.0d, 50.0d, 100.0d, 400.0d));
    global.setArenaSectionState(2, AREA_TYPE_BASE);


    // Setup spawnpoints
    global.addSpawnPoint(spawnpoint())

    global.addSoldier(soldier());
//    // TODO: Random Soldiers
//    nextsoldier.color_red = 0.5d; nextsoldier.color_green = 0.8d; nextsoldier.color_blue = 0.0d;
//    nextsoldier.m_ab_viewrange = 10.0;
//    nextsoldier.giveObjective(0.0d, 0.0d, nextsoldier.TRANSIT_TYPE_GUNRUN, nextsoldier.OBJECTIVE_TYPE_JUSTMOVE);


    for(unsigned int addsol = 0; addsol < 1; addsol ++){
        //team0.soldiers.at(addsol).spos(-320.0d, -50.0d + 20.0d * addsol);
        //team1.soldiers.at(addsol).spos(+320.0d, -60.0d + 20.0d * addsol);
    }



    /// Team and Player Stuff

    // Main loop
    glutMainLoop();

    return EXIT_SUCCESS;
}
