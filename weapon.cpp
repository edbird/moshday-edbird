
#include "weapon.hpp"

weapon::weapon(const unsigned char weapon_type_id)
{
    weapontypeid = weapon_type_id;

    //if(weapontypeid == TYPEID_ASSAULTRIFLE){
        firepower = 0.35d;
        damagerad = 0.1e-3d;
        defence = 0.0d;
        range = 100.0d;
        velocity = 900.0d;
        accuracyperrange = 0.65;
    //}
}

weapon::~weapon()
{

}

weapon::weapon(const weapon& clone)
{
    firepower = clone.firepower;
    damagerad = clone.damagerad;
    defence = clone.defence;
    range = clone.range;
    velocity = clone.velocity;
    accuracyperrange = clone.accuracyperrange;
}

const weapon& weapon::operator=(const weapon& other)
{
    firepower = other.firepower;
    damagerad = other.damagerad;
    defence = other.defence;
    range = other.range;
    velocity = other.velocity;
    accuracyperrange = other.accuracyperrange;
}

void weapon::draw()
{

}
