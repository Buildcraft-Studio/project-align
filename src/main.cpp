#include <iostream>
#include "Point2D.hpp"
#include "Vector2D.hpp"
#include "Polygon.hpp"
#include "Line2D.hpp"
#include "Circle2D.hpp"

int main() {
    Point2D p1(1, 2), p2(3, 4);
    Vector2D v1(1, 1), v2(2, 3);
    Line2D line(p1, p2);

    std::cout << "Point p1: " << p1 << std::endl;
    std::cout << "Point p2: " << p2 << std::endl;

    std::cout << "Vector v1: " << v1 << std::endl;
    std::cout << "Vector v2: " << v2 << std::endl;

    std::cout << "v1 + v2 = " << v1 + v2 << std::endl;
    std::cout << "v1 * 2 = " << v1 * 2 << std::endl;
    std::cout << "v1 / 2 = " << v1 / 2 << std::endl;

    Polygon polygon({p1, p2});
    std::cout << polygon << std::endl;

    std::cout << line << std::endl;

    Circle2D c(Point2D(3, 4), 5);
    
    std::cout << "Circle center: " << c.getCenter() << std::endl;
    std::cout << "Circle radius: " << c.getRadius() << std::endl;
    std::cout << "Circle area: " << c.area() << std::endl;
    std::cout << "Circle circumference: " << c.circumference() << std::endl;
    

    return 0;
}
