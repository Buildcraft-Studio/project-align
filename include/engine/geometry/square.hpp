#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "geometry/polygon.hpp"

class Square : public Polygon {
public:
    // Constructor
    Square(float length);

    float area() const;

private:
    float side_length; // Define side_length
};

#endif // SQUARE_HPP
