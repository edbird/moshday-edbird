
#include "top-down-cam.hpp"

tdc::tdc()
{
    m_center_pos.reset();
    m_width_height.sxyz(100.0d, 100.0d, 0.0d);
    m_cam_vel = 0.0d;
}

tdc::~tdc()
{

}

tdc::tdc(const tdc& clone)
{
    m_center_pos = clone.m_center_pos;
    m_width_height = clone.m_width_height;
}

const tdc& tdc::operator=(const tdc& other)
{
    m_center_pos = other.m_center_pos;
    m_width_height = other.m_width_height;
}

/// *************************************** ///

double tdc::left()
{
    return m_center_pos.x() - (m_width_height.x() / 2);
}

double tdc::right()
{
    return m_center_pos.x() + (m_width_height.x() / 2);
}

double tdc::top()
{
    return (m_center_pos.y() + (m_width_height.x() / 2)) * m_w2h_ratio;
}

double tdc::bottom()
{
    return (m_center_pos.y() - (m_width_height.x() / 2)) * m_w2h_ratio;
}

double tdc::near()
{
    return -10.0d;
}

double tdc::far()
{
    return +10.0d;
}

/// ******************************************* ///

void tdc::set_centre_x(double arg)
{
    m_center_pos.sx(arg);
}

void tdc::set_centre_y(double arg)
{
    m_center_pos.sy(arg);
}

void tdc::set_width(double arg)
{
    m_width_height.sx(arg);
}

void tdc::set_w2h_ratio(double arg)
{
    m_w2h_ratio = arg;
}

//void tdc::set_height(double arg)
//{
//    m_width_height.sy(arg);
//}

/// ******************************************* ///

void tdc::moveUp()
{
    m_center_pos.sy(m_center_pos.y() + m_cam_vel);
}

void tdc::moveDown()
{
    m_center_pos.sy(m_center_pos.y() - m_cam_vel);
}

void tdc::moveRight()
{
    m_center_pos.sx(m_center_pos.x() + m_cam_vel);
}

void tdc::moveLeft()
{
    m_center_pos.sx(m_center_pos.x() - m_cam_vel);
}

void tdc::set_cam_vel(double arg)
{
    m_cam_vel = arg;
}

/// ******************************************* ///



tdc camera = tdc();
void* tdc_camera_follow = NULL;
