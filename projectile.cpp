
#include <GL/glut.h>

#include "main.hpp"
#include "myOpenGLDrawingMethods.hpp"

#include "projectile.hpp"

projectile::projectile()
{
    m_max_range = 100.0d;
    m_vel.reset();
    m_pos.reset();
    m_travel_dist = 0.0d;

    m_rad = 0.1d;
    live = true;
}

projectile::~projectile()
{

}

projectile::projectile(const projectile& clone)
{
    m_max_range = clone.m_max_range;
    m_vel = clone.m_vel;
    m_pos = clone.m_pos;
    m_travel_dist = clone.m_travel_dist;
    live = clone.live;

    m_rad = clone.m_rad;
}

const projectile& projectile::operator=(const projectile& other)
{
    if(this != &other){ //TODO: check other classes for this protection
        m_max_range = other.m_max_range;
        m_vel = other.m_vel;
        m_pos = other.m_pos;
        m_travel_dist = other.m_travel_dist;
        live = other.live;

        m_rad = other.m_rad;
    }
    return *this;
}

void projectile::cont()
{
    if(live){
        m_pos += m_vel * time_step;
        m_travel_dist += m_vel.mod() * time_step;
        if(m_travel_dist > m_max_range){
            live = false;
        }
    }
}

void projectile::set_pos(double x, double y)
{
    m_pos.sxyz(x, y, 0.0d);
}

void projectile::set_vel(double x, double y)
{
    m_vel.sxyz(x, y, 0.0d);
}

void projectile::set_range(double arg)
{
    m_max_range = arg;
}

void projectile::draw()
{
    if(live){
        // Reset Position
        glLoadIdentity();

        // Draw
        glColor3d(1.0d, 1.0d, 1.0d);
        drawMyCircle(m_rad, m_pos.x(), m_pos.y()); //TODO
    }
}
