#include "geometry.h"
#include <iostream>

namespace Geometry {

    // Circle implementation
    Circle::Circle(Point center, double radius) : center(center), radius(radius) {}

    double Circle::area() const {
        return M_PI * radius * radius;
    }

    double Circle::perimeter() const {
        return 2 * M_PI * radius;
    }

    bool Circle::containsPoint(const Point& point) const {
        return center.distanceTo(point) <= radius;
    }

    void Circle::display() const {
        std::cout << "Circle (Center: ";
        center.display();
        std::cout << ", Radius: " << radius << ")";
    }

    // Rectangle implementation
    Rectangle::Rectangle(Point topLeft, double width, double height)
        : topLeft(topLeft), width(width), height(height) {}

    double Rectangle::area() const {
        return width * height;
    }

    double Rectangle::perimeter() const {
        return 2 * (width + height);
    }

    bool Rectangle::containsPoint(const Point& point) const {
        double x = point.getX();
        double y = point.getY();
        return x >= topLeft.getX() && x <= (topLeft.getX() + width) &&
               y <= topLeft.getY() && y >= (topLeft.getY() - height);
    }

    void Rectangle::display() const {
        std::cout << "Rectangle (Top-Left: ";
        topLeft.display();
        std::cout << ", Width: " << width << ", Height: " << height << ")";
    }

    // Triangle implementation
    Triangle::Triangle(Point v1, Point v2, Point v3)
        : vertex1(v1), vertex2(v2), vertex3(v3) {}

    double Triangle::area() const {
        return std::abs(
            (vertex1.getX() * (vertex2.getY() - vertex3.getY()) +
             vertex2.getX() * (vertex3.getY() - vertex1.getY()) +
             vertex3.getX() * (vertex1.getY() - vertex2.getY())) /
            2.0);
    }

    double Triangle::perimeter() const {
        return vertex1.distanceTo(vertex2) + vertex2.distanceTo(vertex3) +
               vertex3.distanceTo(vertex1);
    }

    bool Triangle::containsPoint(const Point& point) const {
        // Check if the point lies inside the triangle using the area method
        double A = area();
        double A1 = Triangle(point, vertex2, vertex3).area();
        double A2 = Triangle(vertex1, point, vertex3).area();
        double A3 = Triangle(vertex1, vertex2, point).area();

        return std::abs(A - (A1 + A2 + A3)) < 1e-6; // Allow small floating-point error
    }

    void Triangle::display() const {
        std::cout << "Triangle (Vertex 1: ";
        vertex1.display();
        std::cout << ", Vertex 2: ";
        vertex2.display();
        std::cout << ", Vertex 3: ";
        vertex3.display();
        std::cout << ")";
    }
}
