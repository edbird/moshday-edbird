#include <GL/glut.h>

#include "top-down-cam.hpp"
#include "team.hpp"
#include "main.hpp"

// Globals (for timers)
double time_step = 25.0d / 1000.0d;
double fps = 1.0d / time_step;
int ms_delay = 25;
bool human_is_playing = true;
soldier* human_soldier;

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
        if(human_is_playing){
            human_soldier->moveUp();
            vector3d temp_vector = human_soldier->pos();
            camera.set_centre_y(temp_vector.y());
        }
        else{
            camera.moveUp();
        }
    }
    if(keys['s']){
        if(human_is_playing){
            human_soldier->moveDown();
            vector3d temp_vector = human_soldier->pos();
            camera.set_centre_y(temp_vector.y());
        }
        else{
            camera.moveDown();
        }
    }
    if(keys['d']){
        if(human_is_playing){
            human_soldier->moveRight();
            vector3d temp_vector = human_soldier->pos();
            camera.set_centre_x(temp_vector.x());
        }
        else{
            camera.moveRight();
        }
    }
    if(keys['a']){
        if(human_is_playing){
            human_soldier->moveLeft();
            vector3d temp_vector = human_soldier->pos();
            camera.set_centre_x(temp_vector.x());
        }
        else{
            camera.moveLeft();
        }
    }

    if(keys['.']){
        if(human_is_playing){
            human_soldier->rotviewdir(-0.1d);
        }
        else{

        }
    }
    if(keys[',']){
        if(human_is_playing){
            human_soldier->rotviewdir(0.1d);
        }
        else{

        }
    }

    if(keys[' ']){
            human_soldier->fire();
        if(human_is_playing){
        }
        else{

        }
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

