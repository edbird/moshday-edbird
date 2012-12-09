

#include "vector3d.hpp"

#ifndef __TOP_DOWN_CAM__HPP__
#define __TOP_DOWN_CAM__HPP__

class tdc{

    public:
        // Constructor
        tdc();
        ~tdc();
        tdc(const tdc& clone);
        const tdc& operator=(const tdc& other);

        // Get Position Methods
        double left();
        double right();
        double top();
        double bottom();
        double near();
        double far();

        // Set Position Methods
        void set_centre_x(double arg);
        void set_centre_y(double arg);
        void set_width(double arg);
        void set_w2h_ratio(double arg);
//        void set_height(double arg);

        // Movement Control
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();

        void set_cam_vel(double arg);

    protected:

    private:
        vector3d m_center_pos;
        vector3d m_width_height;
        double m_w2h_ratio;

        double m_cam_vel;
};

extern tdc camera;
extern void* tdc_camera_follow;

#endif
