
#include <vector>

#include "vector3d.hpp"

#ifndef __SPAWNPOINT__HPP__
#define __SPAWNPOINT__HPP__

class spawnpoint{

    public:
        spawnpoint();
        spawnpoint(double, double);
        ~spawnpoint();
        spawnpoint(const spawnpoint& clone);
        const spawnpoint& operator=(const spawnpoint& other);

        vector3d pos;

        void draw();

    protected:

    private:
        const double SIZE = 3.0d;

};

#endif
