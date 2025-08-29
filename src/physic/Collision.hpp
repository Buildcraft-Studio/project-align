#pragma once
#include "DesVeloAng.hpp"

namespace physic {

// Calculates 1D elastic collision force and updates velocities
void resolveCollision(
    DynamicsProperties& objA,
    DynamicsProperties& objB
);

}