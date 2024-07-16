#include <iostream>
#include <vector>
#include "geometry/Point2D.hpp"
#include "geometry/Line2D.hpp"
#include "geometry/Vector2D.hpp"
#include "geometry/Polygon.hpp"

int main()
{
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;

    std::cout << "v3: (" << v3.x << ", " << v3.y << ")\n";
    std::cout << "v4: (" << v4.x << ", " << v4.y << ")\n";
    std::cout << "Dot product: " << v1.dot(v2) << "\n";
    std::cout << "Magnitude of v1: " << v1.magnitude() << "\n";
    Vector2D v1Normalized = v1.normalize();
    std::cout << "Normalized v1: (" << v1Normalized.x << ", " << v1Normalized.y << ")\n";

    Point2D p1(1, 2);
    Point2D p2(3, 4);
    Line2D line(p1, p2);

    std::cout << "Line equation: " << line.a << "x + " << line.b << "y + " << line.c << " = 0\n";

    Point2D testPoint(2, 3);
    if (line.isPointOnLine(testPoint))
    {
        std::cout << "Point (" << testPoint.x << ", " << testPoint.y << ") is on the line.\n";
    }
    else
    {
        std::cout << "Point (" << testPoint.x << ", " << testPoint.y << ") is not on the line.\n";
    }

    std::vector<Point2D> vertices = {
        Point2D(0, 0),
        Point2D(4, 0),
        Point2D(4, 3),
        Point2D(0, 3)
    };
    Polygon polygon(vertices);

    std::cout << "Perimeter: " << polygon.perimeter() << std::endl;
    std::cout << "Area: " << polygon.area() << std::endl;
    return 0;
}
