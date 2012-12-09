
#include <vector>

#include "vector3d.hpp"

#ifndef __OBJECTIVE__HPP__
#define __OBJECTIVE__HPP__

class objective{

    public:
        objective();
        objective(double, double);
        ~objective();
        objective(const objective& clone);
        const objective& operator=(const objective& other);

        vector3d pos;

        void draw();

    protected:

    private:
        const double SIZE = 3.0d;
};

#endif
