
#include "soldier.hpp"

#include <GL/glut.h>

#include "myOpenGLDrawingMethods.hpp"

soldier::soldier()
{
    m_team_id = 0; // No assigned team
    m_enemyteambits = 0x0;
    m_teamidbits = 0x0;

    m_pos.reset();
    m_major_objective.reset();
    m_minor_objective.reset();

    m_health = 1.0d;
}

soldier::~soldier()
{
    // Nothing to free
}

soldier::soldier(const soldier& clone)
{
    m_team_id = clone.m_team_id;
    m_enemyteambits = clone.m_enemyteambits;
    m_teamidbits = clone.m_teamidbits;

    m_pos = clone.m_pos;
    m_major_objective = clone.m_major_objective;
    m_minor_objective = clone.m_minor_objective;

    m_health = clone.m_health;
}

const soldier& soldier::operator=(const soldier& other)
{
    if(this == &other){
        //TODO: what goes here?
    }

    m_team_id = other.m_team_id;
    m_enemyteambits = other.m_enemyteambits;
    m_teamidbits = other.m_teamidbits;

    m_pos = other.m_pos;
    m_major_objective = other.m_major_objective;
    m_minor_objective = other.m_minor_objective;

    m_health = other.m_health;

    return *this;
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void soldier::spawn(const spawnpoint& thespawnpoint)
{
    if(m_team_id > 0 && m_team_id <= 64){
        // Don't spawn without a team!
        m_pos.sxyz(thespawnpoint.pos.x(), thespawnpoint.pos.y(), 0.0d);
    }
    else{
        std::cout << "Failed to spawn: No team id set." << std::endl;
    }
}

/// ******** ******** ******** ******** ******** ******** ******** ******** ///

void soldier::draw() const
{
    // Draw health bars
    glColor3d(1.0d, 0.66d, 0.0d);
        glVertex2d(m_pos.x(), m_pos.y());
        glVertex2d(m_pos.x() + 20.0d * m_health, m_pos.y());
        glVertex2d(m_pos.x() + 20.0d * m_health, m_pos.y() + 4.0d);
        glVertex2d(m_pos.x(), m_pos.y() + 4.0d);
    glEnd();

    glColor3d(0.8d, 0.8d, 0.8d);
    glBegin(GL_LINE_LOOP);
        glVertex2d(m_pos.x(), m_pos.y());
        glVertex2d(m_pos.x() + 20.0d, m_pos.y());
        glVertex2d(m_pos.x() + 20.0d, m_pos.y() + 4.0d);
        glVertex2d(m_pos.x(), m_pos.y() + 4.0d);
    glEnd();

    //TODO:
    glColor3d(1.0d, 0.0d, 0.0d);
    drawMyCircle(5.0d, m_pos.x(), m_pos.y());
}
