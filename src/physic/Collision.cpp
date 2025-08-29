#include "Collision.hpp"

namespace physic {

void resolveCollision(DynamicsProperties& objA, DynamicsProperties& objB) {
    // 1D elastic collision along x axis
    float v1 = objA.velocity.getX();
    float v2 = objB.velocity.getX();
    float m1 = objA.mass;
    float m2 = objB.mass;

    float newV1 = (v1 * (m1 - m2) + 2 * m2 * v2) / (m1 + m2);
    float newV2 = (v2 * (m2 - m1) + 2 * m1 * v1) / (m1 + m2);

    objA.velocity.setX(newV1);
    objB.velocity.setX(newV2);

    // You can expand this for y axis or angular velocity if needed
}

}