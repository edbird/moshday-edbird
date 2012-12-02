#include <GL/glut.h>

#include "top-down-cam.hpp"
#include "team.hpp"
#include "main.hpp"

// Globals (for timers)
double time_step = 25.0d / 1000.0d;
double fps = 1.0d / time_step;
int ms_delay = 25;

void handleTimer(int value){

    // Move Camera
//    vector3d t_vec;
//    t_vec = team0.soldiers.at(0).pos();
//    camera.set_centre_x(t_vec.x());
//    t_vec = team0.soldiers.at(0).pos();
//    camera.set_centre_y(t_vec.y());

    // Handle Keyboard keydown
    if(keys['w']){
        //team0.soldiers.at(0).moveUp();
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


    for(int s = 0; s < team0.m_n_soldiers; s ++){
        team0.soldiers.at(s).cont(team1.soldiers, team1.m_n_soldiers);
    }

    for(int s = 0; s < team1.m_n_soldiers; s ++){
        team1.soldiers.at(s).cont(team1.soldiers, team1.m_n_soldiers);
    }

    // Refresh screen
    glutPostRedisplay();
    // 40 FPS
    glutTimerFunc(ms_delay, handleTimer, value + 1); // TODO: CHANGE FOR SDL DELAY AND INFINITE LOOP WITH TIMEING
}

