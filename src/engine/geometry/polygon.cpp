#include "geometry/polygon.hpp"
#include "geometry/line.hpp"

polygon::polygon(const std::vector<point>& points) : vertices(points) {}

float polygon::perimeter() const {
    float perimeter = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        point current = vertices[i];
        point next = vertices[(i + 1) % vertices.size()];
        line edge(current, next);
        perimeter += edge.length();
    }
    return perimeter;
}
