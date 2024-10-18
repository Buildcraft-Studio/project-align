#include "geometry/line.hpp"
#include <cmath>

float Line::length() const {
    float dx = p2.getX() - p1.getX();
    float dy = p2.getY() - p1.getY();
    return std::sqrt(dx * dx + dy * dy);
}
