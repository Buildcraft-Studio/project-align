#include "geometry/square.hpp"

// Constructor
Square::Square(float length) : Polygon({
    Point(0, 0), 
    Point(length, 0), 
    Point(length, length), 
    Point(0, length)
}), side_length(length) {}

// Calculate the area of the square
float Square::area() const {
    return side_length * side_length;
}
