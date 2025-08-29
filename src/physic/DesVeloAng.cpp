#include "DesVeloAng.hpp"

namespace physic {

void calculateDynamics(DynamicsProperties& props) {
    // Linear acceleration: a = F / m
    float ax = props.force / props.mass;
    float ay = props.force / props.mass; // For simplicity, same force in both axes

    // Update velocity: v = v + a * dt
    props.velocity.setX(props.velocity.getX() + ax * props.dt);
    props.velocity.setY(props.velocity.getY() + ay * props.dt);

    // Update position: p = p + v * dt
    props.position.setX(props.position.getX() + props.velocity.getX() * props.dt);
    props.position.setY(props.position.getY() + props.velocity.getY() * props.dt);

    // Angular acceleration: alpha = torque / mass (simplified)
    float angularAcc = props.torque / props.mass;
    props.angularVelocity += angularAcc * props.dt;
}

}