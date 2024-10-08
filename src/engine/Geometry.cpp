#include "Geometry.h"
#include <iostream>

// Geometry implementation for polygons
void Geometry::drawPolygon(const Polygon& polygon) {
    // Code to draw the polygon using vertices
    std::cout << "Drawing polygon with vertices: ";
    for (const auto& vertex : polygon.vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;
}
