#ifndef POINT_HPP
#define POINT_HPP

class Point {
private:
    float x;
    float y;

public:
    // Constructor definition (inline)
    Point(float x_val, float y_val) : x(x_val), y(y_val) {}

    // Getters for x and y (optional)
    float getX() const { return x; }
    float getY() const { return y; }
};

#endif // POINT_HPP
