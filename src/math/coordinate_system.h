#ifndef COORDINATE_SYSTEM_H
#define COORDINATE_SYSTEM_H

#include <cmath>
#include <iostream>

class Point {
private:
    double x, y;

public:
    // Constructor
    Point(double x = 0.0, double y = 0.0);

    // Setter methods
    void setX(double x);
    void setY(double y);
    void setXY(double x, double y);

    // Getter methods
    double getX() const;
    double getY() const;

    // Distance to another point
    double distanceTo(const Point& other) const;

    // Display point coordinates
    void display() const;
};

#endif // COORDINATE_SYSTEM_H
