#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class vector2 {
public:
    float x, y;

    // Constructors
    vector2();
    vector2(float x, float y);

    // Basic operations
    vector2 operator+(const vector2& other) const;
    vector2 operator-(const vector2& other) const;
    vector2 operator*(float scalar) const;
    vector2 operator/(float scalar) const;

    // Magnitude and normalization
    float magnitude() const;
    vector2 normalized() const;
};

#endif // VECTOR2_HPP
