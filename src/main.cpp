#include <iostream>
#include <vector>
#include "geometry/geometry.h"

#include "randomID/uniID.h"

int main() {
    std::vector<point> polygon = {{0, 0}, {4, 0}, {4, 4}, {0, 4}};
    point testPoint(2, 2);

    if (is_inside_polygon(polygon, testPoint)) {
        std::cout << "The point is inside the polygon.\n";
    } else {
        std::cout << "The point is outside the polygon.\n";
    }


    uniID localUD;
        localUD.setSeed(12345);

    std::cout << "Random ID: " << localUD.getUniID() << std::endl;
    std::cout << "Random ID: " << localUD.getUniID() << std::endl;
    std::cout << "Seed: " << localUD.getSeed() << std::endl;
    return 0;


}
