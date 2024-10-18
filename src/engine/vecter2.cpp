#include "vector2.hpp"
#include <cmath>

vector2::vector2() : x(0), y(0) {}
vector2::vector2(float x, float y) : x(x), y(y) {}

vector2 vector2::operator+(const vector2& other) const {
    return vector2(x + other.x, y + other.y);
}

vector2 vector2::operator-(const vector2& other) const {
    return vector2(x - other.x, y - other.y);
}

vector2 vector2::operator*(float scalar) const {
    return vector2(x * scalar, y * scalar);
}

vector2 vector2::operator/(float scalar) const {
    return vector2(x / scalar, y / scalar);
}

float vector2::magnitude() const {
    return std::sqrt(x * x + y * y);
}

vector2 vector2::normalized() const {
    float mag = magnitude();
    return vector2(x / mag, y / mag);
}
