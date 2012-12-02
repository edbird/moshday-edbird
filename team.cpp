
#include "team.hpp"


team::team()
{
    //todo:
}

team::~team()
{
    //todo:
}

team::team(const team& clone)
{
    //todo:
}

const team& team::operator=(const team& other)
{
    //todo:
}

void team::addSoldier(const soldier& newSoldier)
{
    soldiers.push_back(newSoldier);
    m_n_soldiers ++;
}

void team::setEnemy(team* enemy)
{
    v_enemyteams.push_back(enemy);
    enemy->v_enemyteams.push_back(enemy);
}

const std::vector<team*>& team::getEnemy()
{
    return v_enemyteams;
}
//
//bool team::isAlly(const soldier& checksoldier)
//{
//    for(int ch = 0; ch < m_n_soldiers; ch ++)
//    {
//        if(&v_enemyteams.at(ch) == &checksoldier)
//        {
//            // Is an enemy
//            return false;
//        }
//    }
//    return true;
//}

team team0 = team();
team team1 = team();

team* player_ally = &team0;
