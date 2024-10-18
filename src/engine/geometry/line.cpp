#include "geometry/line.hpp"
#include <cmath>

line::line() : start(point()), end(point()) {}

line::line(const point& start_val, const point& end_val) : start(start_val), end(end_val) {}

float line::length() const {
    return start.distance_to(end);
}
