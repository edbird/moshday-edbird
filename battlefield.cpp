
#include <GL/glut.h>

#include "battlefield.hpp"

//battlefield::battlefield(const void* const collected_pointer)// : p_collected(collected_pointer)
//{
//    m_pos.reset();
//    m_size.reset();
//}

battlefield::battlefield(const vector3d& pos, const vector3d& size)
{
    m_pos.sxyz(pos.x(), pos.y(), 0.0d);
    m_size.sxyz(size.x(), size.y(), 0.0d);
}

battlefield::battlefield(double x, double y, double w, double h)
{
    m_pos.sxyz(x, y, 0.0d);
    m_size.sxyz(w, h, 0.0d);
}

battlefield::~battlefield()
{
    // Nothing to free
}

battlefield::battlefield(const battlefield& clone)// : p_collected(clone.p_collected)
{
    m_pos = clone.m_pos;
    m_size = clone.m_size;
}

const battlefield& battlefield::operator=(const battlefield& other)
{
    if(this == &other){
        //TODO: dont know what to do?
    }

    m_pos = other.m_pos;
    m_size = other.m_size;

    return *this;
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void battlefield::draw() const
{

    // Reset Position
    glLoadIdentity();

    // Draw
    switch(m_area_type){
        case AREA_TYPE_BATTLEFIELD:
            glColor3d(1.0d, 1.0d, 1.0d);
        break;

        case AREA_TYPE_NEUTRAL:
            glColor3d(0.66d, 0.66d, 0.66d);
        break;

        case AREA_TYPE_BASE:
            glColor3d(1.0d, 0.0d, 0.0d);
        break;

        default:
            glColor3d(1.0d, 1.0d, 1.0d);
        break;
    }


    glBegin(GL_LINE_LOOP);
        glVertex2d(m_pos.x(), m_pos.y());
        glVertex2d(m_pos.x() + m_size.x(), m_pos.y());
        glVertex2d(m_pos.x() + m_size.x(), m_pos.y() + m_size.y());
        glVertex2d(m_pos.x(), m_pos.y() + m_size.y());
    glEnd();
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

const vector3d& battlefield::pos()
{
    return m_pos;
}

const vector3d& battlefield::size()
{
    return m_size;
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

double battlefield::posx()
{
    return m_pos.x();
}

double battlefield::posy()
{
    return m_pos.y();
}

double battlefield::sizex()
{
    return m_size.x();
}

double battlefield::sizey()
{
    return m_size.y();
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void battlefield::setpos(const vector3d& newpos)
{
    m_pos = newpos;
}

void battlefield::setsize(const vector3d& newsize)
{
    m_size = newsize;
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void battlefield::setpos(double x, double y)
{
    m_pos.sxyz(x, y, 0.0d);
}

void battlefield::setsize(double x, double y)
{
    m_size.sxyz(x, y, 0.0d);
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void battlefield::setAreaType(AREA_TYPE areatype)
{
    m_area_type = areatype;
}

AREA_TYPE battlefield::getAreaType()
{
    return m_area_type;
}
