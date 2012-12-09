
#include "team.hpp"

team::team(unsigned char teamid)
{
    m_team_uid = teamid;
}

~team::team()
{
    // Nothing to free
}

team::team(const team& clone)
{
    m_team_uid = clone.m_team_uid;
}

const team& team::operator=(const team& other)
{
    m_team_uid = other.m_team_uid;
}




