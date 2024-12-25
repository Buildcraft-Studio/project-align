#include <iostream>
#include <vector>
#include "geometry/geometry.h"

int main() {
    std::vector<point> polygon = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    point testPoint(2, 2);

    if (is_inside_polygon(polygon, testPoint)) {
        std::cout << "The point is inside the polygon.\n";
    } else {
        std::cout << "The point is outside the polygon.\n";
    }

    return 0;
}
