#ifndef DESVELOANG_HPP
#define DESVELOANG_HPP

#include <cmath>
#include "../geometry/geometry.hpp"

namespace physic {

struct DynamicsProperties {
    geometry::point position;
    geometry::point velocity;
    float mass;
    float force;
    float torque;
    float angularVelocity;
    float dt;
};

void calculateDynamics(
    DynamicsProperties& props
);

}

#endif // DESVELOANG_HPP