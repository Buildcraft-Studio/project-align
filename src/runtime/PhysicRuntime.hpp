#pragma once
#include <vector>
#include "../physic/DesVeloAng.hpp"

namespace physic {

class PhysicRuntime {
public:
    PhysicRuntime() = default;

    void addObject(const DynamicsProperties& props);
    void updateAll();

    std::vector<DynamicsProperties>& getObjects();

private:
    std::vector<DynamicsProperties> objects;
};

}