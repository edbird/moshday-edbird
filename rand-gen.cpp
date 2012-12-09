
#include <cstdlib>
#include <ctime>
#include "rand-gen.hpp"


randomgenerator::randomgenerator()
{
    srand(time(NULL));
}



unsigned int randomgenerator::getNextRand()
{
    return rand();
}

unsigned int randomgenerator::getNextRand(unsigned int max)
{
    return rand() % (max + 1);
}

unsigned int randomgenerator::getNextRand(unsigned int min, unsigned int max)
{
    return (rand() % (max - min + 1)) + min;
}
