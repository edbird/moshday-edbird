
/**
  * Team:
  *
  * Has Solders
  * Has a Human or AI Commander
  * Has Alliances and Enemies
  *
  *
  *
  *
  **/

#include <vector>
#include "soldier.hpp"
#include "spawnpoint.hpp"
#include "box.hpp"
#include "battlefield.hpp"
#include "objective.hpp"

#ifndef __COLLECT__HPP__
#define __COLLECT__HPP__

class collect{

    public:
        // Constructor, Destructor and Copy/Assignment Opperators
        collect();
        ~collect();
        collect(const collect& clone);
        const collect& operator=(const collect& other);

        // Setup Methods
        void placeBlocks(unsigned int n_blocks);

        // Team stuff
        private: std::vector<team> m_teams;
        unsigned int m_n_teams;
        public:
        const std::vector<team>& teams();
        unsigned int nteams();
        // Add method
        void addTeams(unsigned char nteams)
        {
            for(unsigned char i = 0; i < nteams; i ++){
                if(m_n_teams >= 64){
                    // Do nothing, too many teams
                    continue;
                }

                m_teams.push_back(team());
            }
        }

        // Vector of Solders
        private: std::vector<soldier> m_soldiers;
        unsigned int m_n_soldiers;
        public:
        const std::vector<soldier>& soldiers();
        unsigned int nsoldiers() { return m_n_soldiers; }
        // Add methods
        void addSoldier(const soldier& newSoldier);
        // Spawn Dead Solders into spawn points
        void spawnSoldiers();

        // Spawnpoints inside arena
        private: std::vector<spawnpoint> m_spawnpoints;
        unsigned int m_n_spawnpoints;
        public:
        const std::vector<spawnpoint>& spawnpoints();
        unsigned int nspawnpoints() { return m_n_spawnpoints; }
        // Add methods
        void addSpawnPoint(double x, double y);

        // Objectives inside arena
        private: std::vector<objective> m_objectives;
        unsigned int m_n_objectives;
        public:
        const std::vector<objective>& objectives();
        unsigned int nobjectives() { return m_n_objectives; }
        // Add methods
        void addObjectiveFlag(double x, double y);


        // Boxes inside arena
        private: std::vector<box> m_boxes;
        unsigned int m_n_boxes;
        public:
        const std::vector<box>& boxes();
        unsigned int nboxes() { return m_n_boxes; }
        // Add methods
        void addBox(double x, double y, double size);


        // Arena
        private: std::vector<battlefield> m_arenasections;
        unsigned int m_n_arenasections;
        public:
        const std::vector<battlefield>& arenasections();
        unsigned int narenasections() { return m_n_arenasections; }
        // Add methods
        void addArenaSection(double x, double y, double w, double h);
        void addArenaSection(vector3d position, vector3d size);
        void addArenaSection(const battlefield& section);
        //
        void setArenaSectionState(unsigned int areaid, AREA_TYPE areatype){
            m_arenasections.at(areaid).setAreaType(areatype);
        }


    protected:

    private:
};

extern collect global;

#endif
