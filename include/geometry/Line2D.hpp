#ifndef LINE2D_HPP
#define LINE2D_HPP

#include <iostream>
#include "Point2D.hpp"

class Line2D
{
private:
    Point2D start;
    Point2D end;

public:
    Line2D(const Point2D &start = Point2D(), const Point2D &end = Point2D())
        : start(start), end(end) {}

    const Point2D &getStart() const { return start; }
    const Point2D &getEnd() const { return end; }

    friend std::ostream &operator<<(std::ostream &os, const Line2D &line)
    {
        os << "Line: " << line.start << " -> " << line.end;
        return os;
    }
};

#endif // LINE2D_HPP
