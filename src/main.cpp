#include <iostream>
#include "Point2D.hpp"
#include "Vector2D.hpp"
#include "Polygon.hpp"
#include "Line2D.hpp"
#include "Circle2D.hpp"
#include "Collision.hpp"

int main() {
    // Create instances of Point2D, Circle, and Polygon
    Point2D point(2.5, 3.5);
    Circle2D circle(Point2D(5, 5), 4);
    std::vector<Point2D> vertices = { Point2D(0, 0), Point2D(4, 0), Point2D(4, 4), Point2D(0, 4) };
    Polygon polygon(vertices);

    // Perform collision checks
    if (Collision::pointPoint(point, Point2D(2, 2))) {
        std::cout << "Point-point collision detected!\n";
    }

    if (Collision::circleCircle(circle, Circle2D(Point2D(8, 8), 2))) {
        std::cout << "Circle-circle collision detected!\n";
    }

    if (Collision::circlePoint(circle, Point2D(6, 5))) {
        std::cout << "Circle-point collision detected!\n";
    }

    if (Collision::circlePolygon(circle, polygon)) {
        std::cout << "Circle-polygon collision detected!\n";
    }

    if (Collision::pointInPolygon(Point2D(1, 1), polygon)) {
        std::cout << "Point is inside polygon!\n";
    }

    // Additional collision checks as needed

    return 0;
    return 0;
}
