#include <vector>

#include "projectile.hpp"
#include "weapon.hpp"
#include "vector3d.hpp"

#ifndef __SOLDER__HPP__
#define __SOLDER__HPP__

class soldier{

    public:
        // Constructors and Assignment Opperators
        soldier();
        ~soldier();
        soldier(const soldier& clone);
        const soldier& operator=(const soldier& other);

        // Move methods
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();

        // Get Position
        const vector3d& pos();

        // Set Position
        void spos(double x, double y);

        // AI continue funtion
        void giveObjective(double obj_x, double obj_y,
                           unsigned char transitType, unsigned char objectiveType);
        void cont(const std::vector<soldier>& enemies, unsigned int n_enemies);

        // Look and Attack
        void look(); /* Scan area for enemies */

        // OpenGL Draw
        void draw();

        // Color
        double color_red, color_green, color_blue;

    protected:

    private:
        // Team Pointer
        //team* m_assigned_team;

        // Fired Projectiles
        std::vector<projectile> shots;

        // Move Method
        const unsigned char MOVE_DIRECTION_UP       = 0;
        const unsigned char MOVE_DIRECTION_DOWN     = 1;
        const unsigned char MOVE_DIRECTION_RIGHT    = 2;
        const unsigned char MOVE_DIRECTION_LEFT     = 3;
        void moveUDLR(unsigned char moveDirection);
        void check_bounds();

        // Position and Movement
        double m_move_timestep;
        vector3d m_pos;
        vector3d m_prev_pos;
        vector3d m_move_dir;
        bool m_sprinting;

        vector3d m_view_dir;
        vector3d m_aim_dir;

        // Current Objective
        vector3d m_objectivepos;
        /*  Objective Types (Transition to Objective):
         *
         *  Gunrun - Move as quickly as possible to target, do not take time to engage targets
         *  Moveup - Move as quickly as possible to target, engaging enemies enroute
         *  Sweep  - Sweep a wide area while moving towards target, engage enemies enroute
         *  Backdoor - Take backdoor routes, engaging enemies only from behind
         *  Evade  - Avoid contact enroute
         *
         */
        /*  Objective Types (Final Objective Type)
         *
         *  Justmove - When at objective, request new instructions
         *  Hold - Hold the area when at objective
         *  Sweep - Sweep area continuously according to radius
         *  Camp - Lockdown area and wait for enemy
         */
    public:
        const unsigned char TRANSIT_TYPE_GUNRUN     = 0;
        const unsigned char TRANSIT_TYPE_MOVEUP     = 1;
        const unsigned char TRANSIT_TYPE_SWEEP      = 2;
        const unsigned char TRANSIT_TYPE_BACKDOOR   = 3;
        const unsigned char TRANSIT_TYPE_EVADE      = 4;

        const unsigned char OBJECTIVE_TYPE_JUSTMOVE = 0;
        const unsigned char OBJECTIVE_TYPE_HOLD     = 1;
        const unsigned char OBJECTIVE_TYPE_SWEEP    = 2;
        const unsigned char OBJECTIVE_TYPE_CAMP     = 3;
    private:

        unsigned long long m_transittype;
        unsigned long long m_objectivetype;
        double m_objectiveradius;
        double m_sweepsize;

        // Equiped Weapons
        weapon* equpied_weapon;
        weapon* weapon_slots[5];

    public:
        // Abilities
        //TODO: implementation of this
        double m_ab_health;
        //double m_ab_damage;
        double m_ab_reload_time;
        double m_ab_fire_rate;
        double m_ab_energy;
        double m_ab_sprint_energy_cost;
        double m_ab_weight;
        double m_ab_energy_recharge;
        double m_ab_speed;
        double m_ab_sprint;
        double m_ab_rotatespeed;
        double m_ab_accurcy;
        double m_ab_firepower;
        double m_ab_strength;
        double m_ab_movenoise;
        double m_ab_viewrange;
        double m_ab_viewangle;
        double m_ab_aggression;
        double m_ab_fear;


        // Levels
        double m_fitness;
        double m_strength;
        double m_agility;
    private:

        // OpenGL and Drawing stuff
        double m_drawrad;


};

#endif
