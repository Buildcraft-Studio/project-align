#ifndef LINE_HPP
#define LINE_HPP

#include "geometry/point.hpp"

class line {
public:
    point start, end;

    line();
    line(const point& start, const point& end);

    float length() const;
};

#endif
