#pragma once

#include <vector>
#include "Point2D.hpp"

class Polygon {
private:
    std::vector<Point2D> vertices;

public:
    Polygon(const std::vector<Point2D>& vertices) : vertices(vertices) {}

    void addVertex(const Point2D& vertex) {
        vertices.push_back(vertex);
    }

    const std::vector<Point2D>& getVertices() const {
        return vertices;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polygon& p) {
        os << "Polygon: ";
        for (const auto& vertex : p.vertices) {
            os << vertex << " ";
        }
        return os;
    }
};
