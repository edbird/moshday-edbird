
// TODO: list
// 1: Get Objective (location) assignment working
// 2: Get Soldier to move to objective
// 3: Put blocks in arena, and get soldier to collide with them
// 4: Put collision detection with arena
// 5: Get soldier to find paths to objectives behind obsticles

#include "vector3d.hpp"
#include "spawnpoint.hpp"
#include "team.hpp"

#ifndef __SOLDIER__HPP__
#define __SOLDIER__HPP__

class soldier{


    public:
        // Constructor and Destructor
        soldier();
        ~soldier();
        soldier(const soldier& clone);
        const soldier& operator=(const soldier& other);


        void setTeamID(unsigned char teamid)
        {
            if(teamid > 0 && teamid <= 64){
                m_team_id = teamid;
            }
            else{
                std::cout << "Not a valid team id number." << std::endl;
            }
        }

        void spawn(const spawnpoint& thespawnpoint);

        void setEnemy(soldier& other)
        {
            m_enemyteambits = 0x1 << other.m_team_id;
            other.m_enemyteambits = 0x1 << m_team_id;
        }
        bool isEnemy(const soldier& other)
        {
            if(m_enemyteambits & other.m_teamidbits){
                // Attack this player if true
                return true;
            }
            // If false, dont attack
            return false;
        }

        ///void getAllData(pass arg by reference)
        // Use this function to ask the soldier what it is doing,
        // and what it's plans are for the future (objective assignment etc)

        //void setObjective()
        // Give soldier an objective

        void draw() const;


    protected:


    private:
        team* m_team_p;

        unsigned long long m_teamidbits;
        unsigned long long m_enemyteambits;
        unsigned char m_team_id;

        vector3d m_pos;
        vector3d m_major_objective;
        vector3d m_minor_objective;

        double m_health;


        /****   Major and Minor Objectives:
            *
            *   Major Objective is something like a base, or previously significant
            *   position. This is where the soldier is aiming to get to in the
            *   longer term.
            *   Minor Objective is how the solder thinks it will get to the Major
            *   Objective. Minor Objectives are like nodes used for searching. The
            *   soldier attains a new minor node from line of sight, and it is
            *   updated frequently.
            */

};

#endif
