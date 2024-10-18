#include "geometry/point.hpp"
#include <cmath>

point::point() : x(0), y(0) {}

point::point(float x_val, float y_val) : x(x_val), y(y_val) {}

float point::distance_to(const point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
