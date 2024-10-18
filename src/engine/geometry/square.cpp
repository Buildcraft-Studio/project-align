#include "geometry/square.hpp"

square::square(float length) : polygon({
    point(0, 0),
    point(length, 0),
    point(length, length),
    point(0, length)
}), side_length(length) {}

float square::area() const {
    return side_length * side_length;
}
