#ifndef CIRCLE2D_HPP
#define CIRCLE2D_HPP
#include <cmath>
#include <iostream>
#include "Point2D.hpp"

class Circle2D
{
private:
    Point2D center;
    float radius;

public:
    Circle2D(const Point2D &center = Point2D(), float radius = 0)
        : center(center), radius(radius) {}

    void setCenter(const Point2D &center)
    {
        this->center = center;
    }

    void setRadius(float radius)
    {
        this->radius = radius;
    }

    float getRadius() const
    {
        return radius;
    }

    Point2D getCenter() const
    {
        return center;
    }

    float area() const
    {
        return M_PI * radius * radius;
    }

    float circumference() const
    {
        return 2 * M_PI * radius;
    }
};

#endif // CIRCLE2D_HPP