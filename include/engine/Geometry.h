#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

struct Polygon {
    std::vector<float> vertices; // List of vertices (x1, y1, x2, y2, ...)
};

class Geometry {
public:
    static void drawPolygon(const Polygon& polygon);
};

#endif // GEOMETRY_H
