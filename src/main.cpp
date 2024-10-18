#include <iostream>
#include "engine/geometry/point.hpp" // Include the Point class header
#include "engine/geometry/rectangle.hpp" // Include the Rectangle class header

int main() {
    // Create a point for the origin of the rectangle
    Point origin(1.0f, 2.0f); // Example coordinates for the rectangle's origin

    // Create a rectangle using the Point and its width and height
    Rectangle rectangle(5.0f, 10.0f, origin); // Width 5, Height 10, Origin at (1, 2)

    // Output the number of sides for the rectangle
    std::cout << "Rectangle has " << rectangle.getNumberOfSides() << " sides.\n";

    return 0;
}
