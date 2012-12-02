
#include "vector3d.hpp"


#ifndef __BATTLEFIELD__HPP__
#define __BATTLEFIELD__HPP__

class battlefield{

    public:
        // Constructor, Destructors
        battlefield();
        ~battlefield();

        // Drawing Method
        void draw();

        // Get
        const vector3d& pos();
        const vector3d& size();
        const vector3d& upleft();
        const vector3d& upright();
        const vector3d& downleft();
        const vector3d& downright();

        // Set - Method 1
        void setpos(const vector3d& newpos);
        void setsize(const vector3d& newsize);
        void setupleft(const vector3d& newupleft);
        void setupright(const vector3d& newupright);
        void setdownleft(const vector3d& newdownleft);
        void setdownright(const vector3d& newdownright);

        // Set - Method 2
        void setpos(double x, double y);
        void setsize(double x, double y);
        void setupleft(double x, double y);
        void setupright(double x, double y);
        void setdownleft(double x, double y);
        void setdownright(double x, double y);


    protected:


    private:
        vector3d m_pos;
        vector3d m_size;
        vector3d m_upleft;
        vector3d m_upright;
        vector3d m_downleft;
        vector3d m_downright;


};

extern battlefield arena;

#endif
