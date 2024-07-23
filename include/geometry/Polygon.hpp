#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <iostream>
#include "Point2D.hpp"

class Polygon
{
private:
    std::vector<Point2D> points;

public:
    Polygon(const std::vector<Point2D> &points = {}) : points(points) {}

    void addPoint(const Point2D &point) { points.push_back(point); }

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
