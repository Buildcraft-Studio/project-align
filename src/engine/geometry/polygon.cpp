#include "geometry/polygon.hpp"

// Constructor
Polygon::Polygon(const std::vector<Point>& points) : vertices(points) {}

// Add a point to the polygon
void Polygon::addPoint(const Point& point) {
    vertices.push_back(point);
}

// Get the number of sides of the polygon
int Polygon::getNumberOfSides() const {
    return vertices.size();
}
