#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "geometry/polygon.hpp"

class square : public polygon {
public:
    float side_length;

    square(float side_length);
    float area() const;
};

#endif
