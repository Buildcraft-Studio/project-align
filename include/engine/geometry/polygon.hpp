#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include "geometry/point.hpp"

class polygon {
public:
    std::vector<point> vertices;

    polygon(const std::vector<point>& points);

    float perimeter() const;
};

#endif
