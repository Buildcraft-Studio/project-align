//uniID.h

#ifndef UNIID_H
#define UNIID_H

#include <cstdlib>

class uniID
{
private:
    int seed;
public:
    void setSeed(int seed);
    int getSeed();
    int getUniID();
};

#endif