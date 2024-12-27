#include "uniID.h"
#include <cstdlib>



    void uniID::setSeed(int seed)
    {
        this->seed = seed;
    };
    int uniID::getSeed()
    {
        return seed;
    };
    int uniID::getUniID()
    {
        srand(seed);
        int uniID = rand();

        return uniID;
    };
