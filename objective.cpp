
#include "myOpenGLDrawingMethods.hpp"

#include "objective.hpp"

objective::objective()
{
    pos.sxyz(0.0d, 0.0d, 0.0d);
}

objective::objective(double x, double y)
{
    pos.sxyz(x, y, 0.0d);
}

objective::~objective()
{
    // Nothing to free
}

objective::objective(const objective& clone)
{
    pos = clone.pos;
}

const objective& objective::operator=(const objective& other)
{
    if(this == &other){
        // TODO: what to put here?
    }

    pos = other.pos;

    return *this;
}

void objective::draw()
{
    drawMyCircle(SIZE, pos.x(), pos.y());
}
