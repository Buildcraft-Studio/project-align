#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include "coordinate_system.h" // Include the Point class

namespace Geometry {

    // Circle class
    class Circle {
    private:
        Point center;
        double radius;

    public:
        Circle(Point center, double radius);

        double area() const;
        double perimeter() const;
        bool containsPoint(const Point& point) const;

        void display() const;
    };

    // Rectangle class
    class Rectangle {
    private:
        Point topLeft;
        double width, height;

    public:
        Rectangle(Point topLeft, double width, double height);

        double area() const;
        double perimeter() const;
        bool containsPoint(const Point& point) const;

        void display() const;
    };

    // Triangle class
    class Triangle {
    private:
        Point vertex1, vertex2, vertex3;

    public:
        Triangle(Point v1, Point v2, Point v3);

        double area() const;
        double perimeter() const;
        bool containsPoint(const Point& point) const;

        void display() const;
    };
}

#endif // GEOMETRY_H
