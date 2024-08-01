#ifndef LINE2D_HPP
#define LINE2D_HPP

#include "Point2D.hpp"
#include "Vector2D.hpp"

class Line2D
{
private:
    Point2D start;
    Point2D end;

public:
    Line2D(const Point2D &start = Point2D(), const Point2D &end = Point2D())
        : start(start), end(end) {}

    Point2D getStart() const { return start; }
    Point2D getEnd() const { return end; }

    void setStart(const Point2D &start) { this->start = start; }
    void setEnd(const Point2D &end) { this->end = end; }

    Vector2D direction() const { return Vector2D(end.getX() - start.getX(), end.getY() - start.getY()); }
    float length() const { return direction().magnitude(); }

    friend std::ostream &operator<<(std::ostream &os, const Line2D &line)
    {
        os << "Line from " << line.getStart() << " to " << line.getEnd();
        return os;
    }
};

#endif // LINE2D_HPP
