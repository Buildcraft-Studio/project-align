#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "vector2.hpp"

class physics {
public:
    vector2 position;
    vector2 velocity;
    vector2 acceleration;

    float rotation;
    float angularVelocity;
    float angularAcceleration;

    float gravity;

    // Constructor
    physics(vector2 initialPosition, float gravityValue = 9.8f);

    // Update physics for each frame
    void update(float deltaTime);

    // Apply forces
    void applyForce(const vector2& force);
    void applyTorque(float torque);
};

#endif // PHYSICS_HPP
