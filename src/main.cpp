#include <iostream>
#include "geometry/Point2D.hpp"
#include "geometry/Vector2D.hpp"
#include "geometry/Polygon.hpp"
#include "physics/PhysicsEngine.hpp"

int main()
{
    PhysicsEngine engine;

    Point2D p1(0, 0);
    Vector2D v1(1, 1);
    Polygon polygon({p1, Point2D(1, 0), Point2D(0, 1)});
    engine.addObject(polygon);

    // Simulate one second
    engine.applyGravity(1.0f);

    std::cout << "Polygon after gravity applied: " << polygon << std::endl;

    return 0;
}
