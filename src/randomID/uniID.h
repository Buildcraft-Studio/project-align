#ifndef UNIID_H
#define UNIID_H

#include <cstdlib>

class uniID
{
private:
    int seed;
public:
    uniID();  // Constructor
    void setSeed(int newSeed);
    int getSeed() const;
    int getUniID();
};

#endif
