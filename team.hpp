
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

#ifndef __TEAM__HPP__
#define __TEAM__HPP__

class team{

    public:
        // Constructor, Destructor and Copy/Assignment Opperators
        team();
        ~team();
        team(const team& clone);
        const team& operator=(const team& other);

        // Vector of Solders
        std::vector<soldier> soldiers;
        void addSoldier(const soldier& newSoldier);
        unsigned int m_n_soldiers;

        // Team mode type (HUMAN/AI)
        void setTeamMode(unsigned char teamMode){
            m_teammode = teamMode;
        }

        void setEnemy(team* enemy);
        //void setNeutral(team* neutral);
        //void setAlly(team* ally);

        const std::vector<team*>& getEnemy();
//
//        bool isAlly(const soldier& checksoldier);

    protected:

    private:
        // Team type - player or AI
        const unsigned char TEAMMODE_HUMAN = 0x0;
        const unsigned char TEAMMODE_AI = 0x1;
        unsigned char m_teammode;

        // Alliances, Neutral and Enemies
        std::vector<team*> v_enemyteams;
        //vector<team*> v_neutralteams;
        //vector<team*> v_alliedteams;
};

extern team team0; extern team team1;
extern team* player_ally;

#endif
