#include "coordinate_system.h"

// Constructor
Point::Point(double x, double y) : x(x), y(y) {}

// Setter methods
void Point::setX(double x) {
    this->x = x;
}

void Point::setY(double y) {
    this->y = y;
}

void Point::setXY(double x, double y) {
    this->x = x;
    this->y = y;
}

// Getter methods
double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

// Distance to another point
double Point::distanceTo(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Display point coordinates
void Point::display() const {
    std::cout << "(" << x << ", " << y << ")";
}
