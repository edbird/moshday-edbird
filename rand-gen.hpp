
//http://www.bedaux.net/mtrand/

#ifndef __RAND_GEN__HPP__
#define __RAND_GEN__HPP__

class randomgenerator{

    public:
        randomgenerator();

        unsigned int getNextRand();
        unsigned int getNextRand(unsigned int max);
        unsigned int getNextRand(unsigned int min, unsigned int max);


    protected:

    private:

};


#endif
