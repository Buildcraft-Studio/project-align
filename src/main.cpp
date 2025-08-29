#include <iostream>
#include <vector>
#include <string>
#include "runtime/exitCode.hpp"
#include "runtime/PhysicRuntime.hpp"
#include "physic/Collision.hpp" // <-- Add this include

int main(int argc, char const *argv[])
{
    try {
        physic::PhysicRuntime runtime;

        // Create two physics objects
        physic::DynamicsProperties objA;
        objA.position = geometry::point(0, 0);
        objA.velocity = geometry::point(1, 0);
        objA.mass = 1.0f;
        objA.force = 0.0f;
        objA.torque = 0.0f;
        objA.angularVelocity = 0.0f;
        objA.dt = 0.1f;

        physic::DynamicsProperties objB;
        objB.position = geometry::point(5, 0);
        objB.velocity = geometry::point(-1, 0);
        objB.mass = 1.0f;
        objB.force = 0.0f;
        objB.torque = 0.0f;
        objB.angularVelocity = 0.0f;
        objB.dt = 0.1f;

        runtime.addObject(objA);
        runtime.addObject(objB);

        std::cout << "Starting physics simulation with collision...\n";
        for (int i = 0; i < 10; ++i) {
            runtime.updateAll();
            auto& objects = runtime.getObjects();

            // Simple collision check: if positions overlap or cross
            if (objects[0].position.getX() >= objects[1].position.getX()) {
                physic::resolveCollision(objects[0], objects[1]);
                std::cout << "Collision resolved at step " << i << "!\n";
            }

            std::cout << "Step " << i << ":\n";
            for (size_t j = 0; j < objects.size(); ++j) {
                std::cout << "  Object " << j << ": Position=("
                          << objects[j].position.getX() << ", "
                          << objects[j].position.getY() << "), "
                          << "Velocity=("
                          << objects[j].velocity.getX() << ", "
                          << objects[j].velocity.getY() << "), "
                          << "AngularVelocity=" << objects[j].angularVelocity
                          << std::endl;
            }
        }
    } catch (const std::exception& e) {
        Runtime::handleException(e);
    } catch (...) {
        Runtime::handleUnknownException();
    }
    return 0;
}
