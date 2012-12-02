
#include <GL/glut.h>

#include "battlefield.hpp"

battlefield::battlefield()
{
    m_pos.reset();
    m_size.reset();
    m_upleft.reset();
    m_upright.reset();
    m_downleft.reset();
    m_downright.reset();
}

battlefield::~battlefield()
{

}

void battlefield::draw()
{

    // Reset Position
    glLoadIdentity();

    // Draw
    glColor3d(1.0d, 1.0d, 1.0d);
    glBegin(GL_LINE_LOOP);
        glVertex2d(m_upleft.x(), m_upleft.y());
        glVertex2d(m_downleft.x(), m_downleft.y());
        glVertex2d(m_downright.x(), m_downright.y());
        glVertex2d(m_upright.x(), m_upright.y());
    glEnd();
}

/// ************************************************

const vector3d& battlefield::pos()
{
    return m_pos;
}

const vector3d& battlefield::size()
{
    return m_size;
}

const vector3d& battlefield::upleft()
{
    return m_upleft;
}

const vector3d& battlefield::upright()
{
    return m_upright;
}

const vector3d& battlefield::downleft()
{
    return m_downleft;
}

const vector3d& battlefield::downright()
{
    return m_downright;
}

/// ************************************************

void battlefield::setpos(const vector3d& newpos)
{
    m_pos = newpos;
    m_upleft = m_pos;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setsize(const vector3d& newsize)
{
    m_size = newsize;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setupleft(const vector3d& newupleft)
{
    m_upleft = newupleft;
    m_pos = m_upleft;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setupright(const vector3d& newupright)
{
    m_upright = newupright;
    m_pos.sxyz(m_upright.x() - m_size.x(), m_upright.y(), 0.0d);
    m_upleft = m_pos;
    m_downleft.sxyz(m_upright.x() - m_size.x(), m_upright.y() - m_size.y(), 0.0d);
    m_downright.sxyz(m_upright.x(), m_upright.y() - m_upright.y(), 0.0d);
}

void battlefield::setdownleft(const vector3d& newdownleft)
{
    m_downleft = newdownleft;
    m_pos.sxyz(m_downleft.x(), m_downleft.y() + m_size.y(), 0.0d);
    m_upleft = m_pos;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setdownright(const vector3d& newdownright)
{
    m_downright = newdownright;
    m_pos = m_downright - m_size;
    m_upleft = m_pos;
    m_upright.sxyz(m_upleft.x() + m_size.y(), m_upleft.y(), 0.0d);
    m_downleft.sxyz(m_upleft.x(), m_upleft.y() - m_size.y(), 0.0d);
}

/// ************************************************
//TODO: check that this actually works (re-write using '.sxyz')
void battlefield::setpos(double x, double y)
{
    m_pos.sxyz(x, y, 0.0d);
    m_upleft = m_pos;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setsize(double x, double y)
{
    m_size.sxyz(x, y, 0.0d);
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setupleft(double x, double y)
{
    m_upleft.sxyz(x, y, 0.0d);
    m_pos = m_upleft;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downleft.sxyz(m_pos.x(), m_pos.y() + m_size.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setupright(double x, double y)
{
    m_upright.sxyz(x, y, 0.0d);
    m_pos.sxyz(m_upright.x() - m_size.x(), m_upright.y(), 0.0d);
    m_upleft = m_pos;
    m_downleft.sxyz(m_upright.x() - m_size.x(), m_upright.y() - m_size.y(), 0.0d);
    m_downright.sxyz(m_upright.x(), m_upright.y() - m_upright.y(), 0.0d);
}

void battlefield::setdownleft(double x, double y)
{
    m_downleft.sxyz(x, y, 0.0d);
    m_pos.sxyz(m_downleft.x(), m_downleft.y() + m_size.y(), 0.0d);
    m_upleft = m_pos;
    m_upright.sxyz(m_pos.x() + m_size.x(), m_pos.y(), 0.0d);
    m_downright = m_pos + m_size;
}

void battlefield::setdownright(double x, double y)
{
    m_downright.sxyz(x, y, 0.0d);
    m_pos = m_downright - m_size;
    m_upleft = m_pos;
    m_upright.sxyz(m_upleft.x() + m_size.y(), m_upleft.y(), 0.0d);
    m_downleft.sxyz(m_upleft.x(), m_upleft.y() - m_size.y(), 0.0d);
}

/// ************************************************

battlefield arena = battlefield();
