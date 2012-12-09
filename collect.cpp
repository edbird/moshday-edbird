
#include "collect.hpp"

collect::collect()
{
    // No default assignments
}

collect::~collect()
{
    if(m_n_soldiers > 0){
        m_soldiers.clear();
    }
    if(m_n_spawnpoints > 0){
        m_spawnpoints.clear();
    }
    if(m_n_objectives > 0){
        m_objectives.clear();
    }
    if(m_n_boxes > 0){
        m_boxes.clear();
    }
}

collect::collect(const collect& clone)
{
    m_n_soldiers = clone.m_n_soldiers;
    m_n_spawnpoints = clone.m_n_spawnpoints;
    m_n_objectives = clone.m_n_objectives;
    m_n_boxes = clone.m_n_boxes;

    for(unsigned int i = 0; i < clone.m_n_soldiers; i ++){
        m_soldiers.push_back(clone.m_soldiers.at(i));
    }
    for(unsigned int i = 0; i < clone.m_n_spawnpoints; i ++){
        m_spawnpoints.push_back(clone.m_spawnpoints.at(i));
    }
    for(unsigned int i = 0; i < clone.m_n_objectives; i ++){
        m_objectives.push_back(clone.m_objectives.at(i));
    }
    for(unsigned int i = 0; i < clone.m_n_boxes; i ++){
        m_boxes.push_back(clone.m_boxes.at(i));
    }
}

const collect& collect::operator=(const collect& other)
{
    //TODO:
}

/// ***** ***** ***** ***** ***** ///

const std::vector<soldier>& collect::soldiers()
{
    return m_soldiers;
}

void collect::addSoldier(const soldier& newsoldier)
{
    m_soldiers.push_back(newsoldier);
    m_n_soldiers ++;
}

void collect::spawnSoldiers()
{
    //TODO:
}

const std::vector<spawnpoint>& collect::spawnpoints()
{
    return m_spawnpoints;
}

void collect::addSpawnPoint(double x, double y)
{
    m_spawnpoints.push_back(spawnpoint(x, y));
    m_n_spawnpoints ++;
}

const std::vector<objective>& collect::objectives()
{
    return m_objectives;
}

void collect::addObjectiveFlag(double x, double y)
{
    m_objectives.push_back(objective(x, y));
    m_n_objectives ++;
}

const std::vector<box>& collect::boxes()
{
    return m_boxes;
}

void collect::addBox(double x, double y, double size)
{
    m_boxes.push_back(box(x, y, size));
    m_n_boxes ++;
}

const std::vector<battlefield>& collect::arenasections()
{
    return m_arenasections;
}

void collect::addArenaSection(double x, double y, double w, double h)
{
    m_arenasections.push_back(battlefield(x, y, w, h));
    m_n_arenasections ++;
}

void collect::addArenaSection(vector3d position, vector3d size)
{
    m_arenasections.push_back(battlefield(position, size));
    m_n_arenasections ++;
}

void collect::addArenaSection(const battlefield& section)
{
    m_arenasections.push_back(section);
    m_n_arenasections ++;
}

collect global = collect();
