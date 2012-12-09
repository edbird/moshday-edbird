
#include "vector3d.hpp"

#ifndef __BATTLEFIELD__HPP__
#define __BATTLEFIELD__HPP__

enum AREA_TYPE : unsigned char{ //TODO: is this useful for anything?
    AREA_TYPE_BATTLEFIELD,
    AREA_TYPE_NEUTRAL,
    AREA_TYPE_BASE
};

class battlefield{

    public:
        // Constructor, Destructors
        //battlefield(const void* const collected_pointer);
        battlefield(const vector3d& pos, const vector3d& size);
        battlefield(double x, double y, double w, double h);
        ~battlefield();
        battlefield(const battlefield& clone);
        const battlefield& operator=(const battlefield& other);

        // Pointer to the collecter
        //const void* const p_collected;

        // Drawing Method
        void draw() const;

        // Get - Method 1
        const vector3d& pos();
        const vector3d& size();

        // Get - Method 2
        //TODO: this is a fudge to get vector3d.x() to work - can it be done another way?
        double posx();
        double posy();
        double sizex();
        double sizey();

        // Set - Method 1
        void setpos(const vector3d& newpos);
        void setsize(const vector3d& newsize);

        // Set - Method 2
        void setpos(double x, double y);
        void setsize(double x, double y);

        // Area Type
        void setAreaType(AREA_TYPE areatype);
        AREA_TYPE getAreaType();


    protected:


    private:
        vector3d m_pos;
        vector3d m_size;

        AREA_TYPE m_area_type;

};

#endif
