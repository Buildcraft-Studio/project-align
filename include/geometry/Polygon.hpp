#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <iostream>
#include "Point2D.hpp"
#include "Vector2D.hpp"

class Polygon
{
private:
    std::vector<Point2D> points;
    Vector2D velocity; // For physics calculations

public:
    Polygon(const std::vector<Point2D> &points = {}) : points(points), velocity(0, 0) {}

    void addPoint(const Point2D &point) { points.push_back(point); }

    void applyForce(const Vector2D &force)
    {
        // Assuming a simple direct addition of force to velocity
        velocity = velocity + force;
    }

    void update(float deltaTime)
    {
        // Update the position of each point based on the velocity and time
        for (auto &point : points)
        {
            point = point + (velocity * deltaTime);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon)
    {
        os << "Polygon: ";
        for (const auto &point : polygon.points)
        {
            os << point << " ";
        }
        return os;
    }
};

#endif // POLYGON_HPP
