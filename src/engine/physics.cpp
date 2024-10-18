#include "physics.hpp"

physics::physics(vector2 initialPosition, float gravityValue) 
    : position(initialPosition), gravity(gravityValue), 
      velocity(vector2(0, 0)), acceleration(vector2(0, 0)),
      rotation(0), angularVelocity(0), angularAcceleration(0) {}

void physics::update(float deltaTime) {
    // Apply gravity
    acceleration.y += gravity;

    // Update velocity and position
    velocity = velocity + acceleration * deltaTime;
    position = position + velocity * deltaTime;

    // Update angular motion
    angularVelocity += angularAcceleration * deltaTime;
    rotation += angularVelocity * deltaTime;

    // Reset acceleration for the next frame
    acceleration = vector2(0, 0);
    angularAcceleration = 0;
}

void physics::applyForce(const vector2& force) {
    acceleration = acceleration + force;
}

void physics::applyTorque(float torque) {
    angularAcceleration += torque;
}
