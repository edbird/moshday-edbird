

#include "vector3d.hpp"


#ifndef __PROJECTILE__HPP__
#define __PROJECTILE__HPP__

class projectile{

    public:
        projectile();
        ~projectile();
        projectile(const projectile& clone);
        const projectile& operator=(const projectile& other);

        void cont();
        void set_pos(double x, double y);
        void set_vel(double x, double y);
        void set_range(double arg);

        void draw();

        double m_rad;

    protected:

    private:
        double m_max_range;
        vector3d m_vel;
        vector3d m_pos;
        double m_travel_dist;

};

#endif
