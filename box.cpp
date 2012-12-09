
#include <GL/glut.h>

#include "box.hpp"

box::box()
{
    pos.reset();
    size = 1.0d;
}

box::box(double x, double y, double _size)
{
    pos.sxyz(x, y, 0.0d);
    size = _size;
}

box::~box()
{
    // Nothing to free
}

box::box(const box& clone)
{
    pos = clone.pos;
    size = clone.size;
}

const box& box::operator=(const box& other)
{
    pos = other.pos;
    size = other.size;
}

void box::draw()
{
    glColor3d(0.6d, 0.6d, 0.6d);
    glBegin(GL_LINE_LOOP);
        glVertex2d(pos.x() - size / 2, pos.y() - size / 2);
        glVertex2d(pos.x() + size / 2, pos.y() - size / 2);
        glVertex2d(pos.x() + size / 2, pos.y() + size / 2);
        glVertex2d(pos.x() - size / 2, pos.y() + size / 2);
    glEnd();
    glBegin(GL_LINES);
        glVertex2d(pos.x() - size / 2, pos.y() - size / 2);
        glVertex2d(pos.x() + size / 2, pos.y() + size / 2);

        glVertex2d(pos.x() - size / 2, pos.y() + size / 2);
        glVertex2d(pos.x() - size / 2, pos.y() + size / 2);
    glEnd();
}
