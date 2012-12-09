
#include "myOpenGLDrawingMethods.hpp"

#include "spawnpoint.hpp"

spawnpoint::spawnpoint()
{
    pos.sxyz(0.0d, 0.0d, 0.0d);
}

spawnpoint::spawnpoint(double x, double y)
{
    pos.sxyz(x, y, 0.0d);
}

spawnpoint::~spawnpoint()
{
    // Nothing to free
}

spawnpoint::spawnpoint(const spawnpoint& clone)
{
    pos.sxyz(clone.pos.x(), clone.pos.y(), 0.0d);
}

const spawnpoint& spawnpoint::operator=(const spawnpoint& other)
{
    if(this == &other){
        //TODO: what goes here?
    }

    pos.sxyz(other.pos.x(), other.pos.y(), 0.0d);

    return *this;
}

void spawnpoint::draw()
{
    drawMyCircle(SIZE, pos.x(), pos.y());
}
