#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <cmath>
#include "Point2D.hpp"

class Polygon {
public:
    std::vector<Point2D> vertices;

    explicit Polygon(const std::vector<Point2D>& vertices) : vertices(vertices) {}

    // Function to calculate the perimeter of the polygon
    double perimeter() const {
        double totalLength = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            size_t next = (i + 1) % vertices.size();
            totalLength += distance(vertices[i], vertices[next]);
        }
        return totalLength;
    }

    // Function to calculate the area of the polygon using the Shoelace formula
    double area() const {
        double sum1 = 0.0;
        double sum2 = 0.0;
        for (size_t i = 0; i < vertices.size(); ++i) {
            size_t next = (i + 1) % vertices.size();
            sum1 += vertices[i].x * vertices[next].y;
            sum2 += vertices[i].y * vertices[next].x;
        }
        return std::abs(sum1 - sum2) / 2.0;
    }

private:
    // Helper function to calculate the distance between two points
    double distance(const Point2D& p1, const Point2D& p2) const {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    }
};

#endif // POLYGON_HPP