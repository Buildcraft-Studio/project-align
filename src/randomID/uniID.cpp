#include "uniID.h"
#include <cstdlib>

// Constructor to initialize seed
uniID::uniID() : seed(0) {}

// Set seed and call srand() once
void uniID::setSeed(int newSeed)
{
    seed = newSeed;
    srand(seed);
}

// Return current seed
int uniID::getSeed() const
{
    return seed;
}

// Generate a unique ID
int uniID::getUniID()
{
    return rand();  // Use the already seeded rand()
}
