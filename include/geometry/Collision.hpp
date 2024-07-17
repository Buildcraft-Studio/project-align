#ifndef COLLISION_HPP
#define COLLISION_HPP


#include <cmath> // For std::sqrt
#include "Point2D.hpp"
#include "Circle2D.hpp"
#include "Polygon.hpp"

namespace Collision {

    // Point vs Point collision check
    inline bool pointPoint(const Point2D& p1, const Point2D& p2) {
        return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
    }

    // Circle vs Circle collision check
    inline bool circleCircle(const Circle2D& c1, const Circle2D& c2) {
        float distanceSquared = (c1.getCenter().getX() - c2.getCenter().getX()) * (c1.getCenter().getX() - c2.getCenter().getX()) +
                                (c1.getCenter().getY() - c2.getCenter().getY()) * (c1.getCenter().getY() - c2.getCenter().getY());
        float radiusSum = c1.getRadius() + c2.getRadius();
        return distanceSquared <= (radiusSum * radiusSum);
    }

    // Circle vs Point collision check
    inline bool circlePoint(const Circle2D& circle, const Point2D& point) {
        float distanceSquared = (point.getX() - circle.getCenter().getX()) * (point.getX() - circle.getCenter().getX()) +
                                (point.getY() - circle.getCenter().getY()) * (point.getY() - circle.getCenter().getY());
        return distanceSquared <= (circle.getRadius() * circle.getRadius());
    }

    // Circle vs Polygon collision check
    inline bool circlePolygon(const Circle2D& circle, const Polygon& polygon) {
        // Implementing a basic bounding box check for simplicity
        // Replace with actual collision detection algorithm
        float minX = std::numeric_limits<float>::max();
        float minY = std::numeric_limits<float>::max();
        float maxX = std::numeric_limits<float>::min();
        float maxY = std::numeric_limits<float>::min();

        for (const auto& vertex : polygon.getVertices()) {
            float x = vertex.getX();
            float y = vertex.getY();
            if (x < minX) minX = x;
            if (x > maxX) maxX = x;
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
        }

        // Bounding box collision check
        float circleDistanceX = std::abs(circle.getCenter().getX() - (minX + maxX) / 2);
        float circleDistanceY = std::abs(circle.getCenter().getY() - (minY + maxY) / 2);

        if (circleDistanceX > (maxX - minX) / 2 + circle.getRadius()) { return false; }
        if (circleDistanceY > (maxY - minY) / 2 + circle.getRadius()) { return false; }

        // Circle overlaps with bounding box, perform more accurate check if needed
        // For demonstration, returning true if bounding box overlaps
        return true;
    }

    // Point in Polygon collision check using ray-casting algorithm
    inline bool pointInPolygon(const Point2D& point, const Polygon& polygon) {
        bool inside = false;
        std::vector<Point2D> vertices = polygon.getVertices();
        int count = vertices.size();
        for (int i = 0, j = count - 1; i < count; j = i++) {
            float xi = vertices[i].getX();
            float yi = vertices[i].getY();
            float xj = vertices[j].getX();
            float yj = vertices[j].getY();
            if (((yi > point.getY()) != (yj > point.getY())) &&
                (point.getX() < (xj - xi) * (point.getY() - yi) / (yj - yi) + xi)) {
                inside = !inside;
            }
        }
        return inside;
    }

} // namespace Collision
#endif