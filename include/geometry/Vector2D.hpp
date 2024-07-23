#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include "Point2D.hpp"

class Vector2D
{
private:
    float x;
    float y;

public:
    Vector2D(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }

    Vector2D operator+(const Vector2D &v) const { return Vector2D(x + v.x, y + v.y); }
    Vector2D operator-(const Vector2D &v) const { return Vector2D(x - v.x, y - v.y); }
    Vector2D operator*(float scalar) const { return Vector2D(x * scalar, y * scalar); }
    Vector2D operator/(float scalar) const { return Vector2D(x / scalar, y / scalar); }

    friend std::ostream &operator<<(std::ostream &os, const Vector2D &v)
    {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

#endif // VECTOR2D_HPP
