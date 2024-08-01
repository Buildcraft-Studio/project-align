#ifndef PHYSICS_ENGINE_HPP
#define PHYSICS_ENGINE_HPP

#include <vector>
#include "geometry/Polygon.hpp"
#include "geometry/Vector2D.hpp"

class PhysicsEngine
{
private:
    std::vector<Polygon> objects;
    Vector2D gravityForce;

public:
    PhysicsEngine(float gravity = 9.8f) : gravityForce(0, -gravity) {}

    void addObject(const Polygon &object)
    {
        objects.push_back(object);
    }

    void applyGravity(float deltaTime)
    {
        for (auto &object : objects)
        {
            object.applyForce(gravityForce);
            object.update(deltaTime);
        }
    }

    void update(float deltaTime)
    {
        for (auto &object : objects)
        {
            object.update(deltaTime);
        }
    }
};

#endif // PHYSICS_ENGINE_HPP
