#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include "geometry/point.hpp"

class Polygon {
public:
    Polygon(const std::vector<Point>& points);
    void addPoint(const Point& point);
    int getNumberOfSides() const;

private:
    std::vector<Point> vertices; // Store the points (vertices) of the polygon
};

#endif // POLYGON_HPP
