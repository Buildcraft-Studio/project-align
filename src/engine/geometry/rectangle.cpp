#include "geometry/rectangle.hpp"

// Constructor
Rectangle::Rectangle(float width, float height, const Point& origin)
    : Polygon({origin,
               Point(origin.getX() + width, origin.getY()),
               Point(origin.getX() + width, origin.getY() + height),
               Point(origin.getX(), origin.getY() + height)}),
      width(width), height(height), origin(origin) {}

// Calculate the area of the rectangle
float Rectangle::area() const {
    return width * height;
}
