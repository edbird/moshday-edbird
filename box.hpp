
#include <vector>

#include "vector3d.hpp"


#ifndef __BOX__HPP__
#define __BOX__HPP__

class box{

    public:
        box();
        box(double, double, double);
        box(const box& clone);
        const box& operator=(const box& other);
        ~box();
        //spawnpoint(const spawnpoint& clone);
        //const spawnpoint& operator=(const spawnpoint& other);

        vector3d pos;
        double size;

        void draw();

    protected:

    private:

};

//extern std::vector<box> boxes;

#endif

