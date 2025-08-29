#include "PhysicRuntime.hpp"

namespace physic {

void PhysicRuntime::addObject(const DynamicsProperties& props) {
    objects.push_back(props);
}

void PhysicRuntime::updateAll() {
    for (auto& obj : objects) {
        calculateDynamics(obj);
    }
}

std::vector<DynamicsProperties>& PhysicRuntime::getObjects() {
    return objects;
}

}