#include <iostream>
#include "math/geometry.h"

int main() {
    using namespace Geometry;

    // Circle example
    Point circleCenter(5, 5);
    Circle circle(circleCenter, 3);
    circle.display();
    std::cout << "\nArea: " << circle.area();
    std::cout << "\nPerimeter: " << circle.perimeter();
    std::cout << "\nContains Point (7, 5): " << (circle.containsPoint(Point(7, 5)) ? "Yes" : "No") << "\n";

    // Rectangle example
    Point rectTopLeft(0, 10);
    Rectangle rectangle(rectTopLeft, 5, 3);
    rectangle.display();
    std::cout << "\nArea: " << rectangle.area();
    std::cout << "\nPerimeter: " << rectangle.perimeter();
    std::cout << "\nContains Point (2, 8): " << (rectangle.containsPoint(Point(2, 8)) ? "Yes" : "No") << "\n";

    // Triangle example
    Triangle triangle(Point(0, 0), Point(5, 0), Point(0, 5));
    triangle.display();
    std::cout << "\nArea: " << triangle.area();
    std::cout << "\nPerimeter: " << triangle.perimeter();
    std::cout << "\nContains Point (2, 2): " << (triangle.containsPoint(Point(2, 2)) ? "Yes" : "No") << "\n";

    return 0;
}
