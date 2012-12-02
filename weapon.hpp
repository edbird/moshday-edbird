
#ifndef __WEAPON__HPP__
#define __WEAPON__HPP__

class weapon{


    public:
        // C & D 'tr
        weapon(const unsigned char weapon_type_id);
        ~weapon();
        weapon(const weapon& clone);
        const weapon& operator=(const weapon& other);

    protected:
        unsigned char weapontypeid;
        double firepower;
        double damagerad;
        double defence;
        double range;
        double velocity;
        double accuracyperrange;

        void draw();

    private:
        const unsigned char TYPEID_KNIFE        = 0;
        const unsigned char TYPEID_PISTOL       = 1;
        const unsigned char TYPEID_ASSAULTRIFLE = 2;
        const unsigned char TYPEID_LASERRIFLE   = 3;
        const unsigned char TYPEID_RPG          = 4;
        const unsigned char TYPEID_FRAG         = 5;
        const unsigned char TYPEID_RIOTSHIELD   = 6;

};

#endif
