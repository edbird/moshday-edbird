#include <GL/glut.h>

#include "top-down-cam.hpp"
#include "collect.hpp"
#include "main.hpp"

// Globals (for timers)
double time_step = 25.0d / 1000.0d;
double fps = 1.0d / time_step;
int ms_delay = 25;

void handleTimer(int value){

    // Handle Keyboard keydown
    if(keys['w']){
        camera.moveUp();
    }
    if(keys['s']){
        camera.moveDown();
    }
    if(keys['d']){
        camera.moveRight();
    }
    if(keys['a']){
        camera.moveLeft();
    }


    for(int s = 0; s < global.nsoldiers(); s ++){
        //TODO
        //collected.soldiers.at(s).cont();
    }


    // Refresh screen
    glutPostRedisplay();
    // 40 FPS
    glutTimerFunc(ms_delay, handleTimer, value + 1); // TODO: CHANGE FOR SDL DELAY AND INFINITE LOOP WITH TIMEING
}

