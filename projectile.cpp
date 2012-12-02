
#include <GL/glut.h>

#include "main.hpp"
#include "myOpenGLDrawingMethods.hpp"

#include "projectile.hpp"

projectile::projectile()
{
    m_max_range = 0.0d;
    m_vel.reset();
    m_pos.reset();
    m_travel_dist = 0.0d;
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
}

const projectile& projectile::operator=(const projectile& other)
{
    if(this != &other){ //TODO: check other classes for this protection
        m_max_range = other.m_max_range;
        m_vel = other.m_vel;
        m_pos = other.m_pos;
        m_travel_dist = other.m_travel_dist;
    }
    return *this;
}

void projectile::cont()
{
    m_pos += m_vel * time_step;
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

    // Reset Position
    glLoadIdentity();

    // Draw
    glColor3d(1.0d, 1.0d, 1.0d);
    drawMyCircle(m_rad, m_pos.x(), m_pos.y()); //TODO
}
