#include <math.h>
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    float x, y;
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    float dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    float magnitude() const {
        return sqrt(x * x + y * y);
    }
    
    float angleWith(const Vector2D& other) const {
        float dotProduct = this->dot(other);
        float magnitudes = this->magnitude() * other.magnitude();
        return std::acos(dotProduct / magnitudes); // Angle in radians
    }

    Vector2D normalize() const {
        float mag = magnitude();
        return Vector2D(x / mag, y / mag);
    }
};

#endif // VECTOR2D_H
