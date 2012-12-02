#include <GL/glut.h>

#include "myOpenGLDrawingMethods.hpp"
#include "main.hpp"
#include "battlefield.hpp"

#include "soldier.hpp"

soldier::soldier() //TODO: rest of variables
{
    //TODO: set everything to random values
    //m_assigned_team = NULL;

    m_move_timestep = ms_delay / 1000.0d;
    m_sprinting = false;
    m_objectivepos.reset();
    m_transittype = TRANSIT_TYPE_GUNRUN;
    m_objectivetype = OBJECTIVE_TYPE_JUSTMOVE;
    m_objectiveradius = 3.0d;
    m_sweepsize = 30.0d;

    m_pos.reset();
    m_prev_pos.reset();

    m_ab_speed = 6.7d / fps;
    m_ab_rotatespeed = (360 / 0.25) / fps;
    m_ab_viewrange = 0.0d;

    m_drawrad = 2.5 * 0.25d;

    color_red = 1.0d; color_green = 1.0d; color_blue = 1.0d;
}

soldier::~soldier()
{
    //TODO: free any memory

}

soldier::soldier(const soldier& clone)
{
    //TODO: copy all values
    //m_assigned_team         = clone.m_assigned_team;

    m_move_timestep         = clone.m_move_timestep;
    m_sprinting             = clone.m_sprinting;
    m_objectivepos          = clone.m_objectivepos;
    m_transittype           = clone.m_transittype;
    m_objectivetype         = clone.m_objectivetype;
    m_objectiveradius       = clone.m_objectiveradius;
    m_sweepsize             = clone.m_sweepsize;

    m_pos                   = clone.m_pos;
    m_prev_pos              = clone.m_prev_pos;

    m_ab_speed              = clone.m_ab_speed;

    m_ab_viewrange          = clone.m_ab_viewrange;

    m_drawrad               = clone.m_drawrad;

    color_red = clone.color_red;
    color_green = clone.color_green;
    color_blue = clone.color_blue;
}

const soldier& soldier::operator=(const soldier& other)
{
    //TODO: copy all values
    if(this != &other){
        //m_assigned_team         = other.m_assigned_team;

        m_move_timestep         = other.m_move_timestep;
        m_sprinting             = other.m_sprinting;
        m_objectivepos          = other.m_objectivepos;
        m_transittype           = other.m_transittype;
        m_objectivetype         = other.m_objectivetype;
        m_objectiveradius       = other.m_objectiveradius;
        m_sweepsize             = other.m_sweepsize;

        m_pos                   = other.m_pos;
        m_prev_pos              = other.m_prev_pos;

        m_ab_speed              = other.m_ab_speed;

        m_ab_viewrange          = other.m_ab_viewrange;

        m_drawrad               = other.m_drawrad;

        color_red = other.color_red;
        color_green = other.color_green;
        color_blue = other.color_blue;
    }
    return *this;
}

/** Drawing Stuff **/

void soldier::draw(){

    // Reset Position
    glLoadIdentity();

    // Move
    //glTranslated(m_pos.x(), m_pos.y(), 0.0d);

    // Draw
    glColor3d(color_red, color_green, color_blue);
    drawMyCircle(m_drawrad, m_pos.x(), m_pos.y()); //TODO
}

/** AI Stuff **/

void soldier::giveObjective(double obj_x, double obj_y, unsigned char transitType, unsigned char objectiveType)
{
    m_objectivepos.sxyz(obj_x, obj_y, 0.0d);
    m_transittype = transitType;
    m_objectivetype  = objectiveType;
}

void soldier::cont(const std::vector<soldier>& enemies, unsigned int n_enemies)
{

    /// Move
    m_move_dir = m_objectivepos - m_pos;
    if(m_move_dir.mod() > m_objectiveradius){
        m_move_dir.normalize();
        if(m_sprinting){
            m_pos.sxyz(m_pos.x() + m_move_dir.x() * m_ab_sprint, m_pos.y() + m_move_dir.y() * m_ab_sprint, 0.0d);
        }
        else{
            m_pos.sxyz(m_pos.x() + m_move_dir.x() * m_ab_speed, m_pos.y() + m_move_dir.y() * m_ab_speed, 0.0d);
        }
    }
    check_bounds();

    /// Look and shoot
    for(unsigned int sc = 0; sc < n_enemies; sc ++){
        soldier t_sol = enemies.at(sc);
        vector3d t_vec;
        t_vec = t_sol.pos();
        t_vec -= pos();
        if(t_vec.mod() < m_ab_viewrange){
            //todo: improve this
            //m_view_dir.move to
            std::cout << "RANGE!" << std::endl;
        }
    }



}

/** Movement Stuff **/

const vector3d& soldier::pos()
{
    return m_pos;
}

void soldier::spos(double x, double y)
{
    m_pos.sxyz(x, y, 0.0d);
}

void soldier::moveUDLR(unsigned char moveDirection)
{
    if(m_sprinting){
        if(moveDirection == MOVE_DIRECTION_UP){
            m_pos.sxyz(m_pos.x(), m_pos.y() + m_ab_sprint, 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_DOWN){
            m_pos.sxyz(m_pos.x(), m_pos.y() - m_ab_sprint, 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_RIGHT){
            m_pos.sxyz(m_pos.x() + m_ab_sprint, m_pos.y(), 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_LEFT){
                m_pos.sxyz(m_pos.x() - m_ab_sprint, m_pos.y(), 0.d);
        }
//        switch(moveDirection){
//            case MOVE_DIRECTION_UP:
//                m_pos.sxyz(m_pos.x(), m_pos.y() + m_ab_sprint, 0.d);
//            break;
//
//            case MOVE_DIRECTION_DOWN:
//                m_pos.sxyz(m_pos.x(), m_pos.y() - m_ab_sprint, 0.d);
//            break;
//
//            case MOVE_DIRECTION_RIGHT:
//                m_pos.sxyz(m_pos.x() + m_ab_sprint, m_pos.y(), 0.d);
//            break;
//
//            case MOVE_DIRECTION_LEFT:
//                m_pos.sxyz(m_pos.x() - m_ab_sprint, m_pos.y(), 0.d);
//            break;
//        }
    }
    else{
        if(moveDirection == MOVE_DIRECTION_UP){
            m_pos.sxyz(m_pos.x(), m_pos.y() + m_ab_speed, 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_DOWN){
            m_pos.sxyz(m_pos.x(), m_pos.y() - m_ab_speed, 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_RIGHT){
            m_pos.sxyz(m_pos.x() + m_ab_speed, m_pos.y(), 0.d);
        }
        if(moveDirection == MOVE_DIRECTION_LEFT){
                m_pos.sxyz(m_pos.x() - m_ab_speed, m_pos.y(), 0.d);
        }
//        switch(moveDirection){
//            case MOVE_DIRECTION_UP:
//                m_pos.sxyz(m_pos.x(), m_pos.y() + m_ab_speed, 0.d);
//            break;
//
//            case MOVE_DIRECTION_DOWN:
//                m_pos.sxyz(m_pos.x(), m_pos.y() - m_ab_speed, 0.d);
//            break;
//
//            case MOVE_DIRECTION_RIGHT:
//                m_pos.sxyz(m_pos.x() + m_ab_speed, m_pos.y(), 0.d);
//            break;
//
//            case MOVE_DIRECTION_LEFT:
//                m_pos.sxyz(m_pos.x() - m_ab_speed, m_pos.y(), 0.d);
//            break;
//        }
    }
    check_bounds();
}

void soldier::check_bounds()
{
    vector3d arena_p = arena.pos();
    vector3d arena_s = arena.size();
    double min_x = arena_p.x();
    double max_x = arena_p.x() + arena_s.x();
    double min_y = arena_p.y();
    double max_y = arena_p.y() + arena_s.y();

    if(m_pos.x() < min_x || m_pos.x() > max_x){
        m_pos.sx(m_prev_pos.x());
    }
    else{
        m_prev_pos.sx(m_pos.x());
    }

    if(m_pos.y() < min_y || m_pos.y() > max_y){
        m_pos.sy(m_prev_pos.y());
    }
    else{
        m_prev_pos.sy(m_pos.y());
    }
}

void soldier::moveUp()
{
    moveUDLR(MOVE_DIRECTION_UP);
}

void soldier::moveDown()
{
    moveUDLR(MOVE_DIRECTION_DOWN);
}

void soldier::moveLeft()
{
    moveUDLR(MOVE_DIRECTION_LEFT);
}

void soldier::moveRight()
{
    moveUDLR(MOVE_DIRECTION_RIGHT);
}