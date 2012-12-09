

#ifndef __TEAM__HPP__
#define __TEAM__HPP__

class team{

    public:
        team(unsigned char team_uid);
        ~team();
        team(const team& clone);
        const team& operator=(const team& other);

    protected:


    private:
        unsigned char m_team_uid;
};

#endif
