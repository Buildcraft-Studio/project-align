#pragma once

#include <iostream>
#include "Point2D.hpp"

class Line2D {
private:
    Point2D start, end;

public:
    Line2D(const Point2D& start, const Point2D& end) : start(start), end(end) {}

    const Point2D& getStart() const {
        return start;
    }

    const Point2D& getEnd() const {
        return end;
    }

    friend std::ostream& operator<<(std::ostream& os, const Line2D& l) {
        os << "Line: " << l.start << " -> " << l.end;
        return os;
    }
};
