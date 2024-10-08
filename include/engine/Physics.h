#ifndef PHYSICS_H
#define PHYSICS_H

class Physics {
public:
    static float calculateVelocity(float position, float time);
    static float calculateAcceleration(float velocity, float time);
};

#endif // PHYSICS_H
