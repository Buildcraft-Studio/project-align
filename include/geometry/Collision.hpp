#pragma once

#include "Point2D.hpp" // Assuming Point2D class is defined in Point2D.hpp
#include "Circle2D.hpp" // Assuming Circle class is defined in Circle.hpp
#include "Vector2D.hpp" // Assuming Vector2D class is defined in Vector2D.hpp
#include "Line2D.hpp" // Assuming Line class is defined in Line.hpp
#include "Polygon.hpp" // Assuming Polygon class is defined in Polygon.hpp

namespace Collision {

    // Point vs Point
    bool pointPoint(const Point2D& p1, const Point2D& p2);

    // Circle vs Circle
    bool circleCircle(const Circle2D& c1, const Circle2D& c2);

    // Circle vs Point
    bool circlePoint(const Circle2D& circle, const Point2D& point);

    // Circle vs Polygon
    bool circlePolygon(const Circle2D& circle, const Polygon& polygon);

    // Point in Polygon (ray-casting)
    bool pointInPolygon(const Point2D& point, const Polygon& polygon);

    // Ray cast from point
    bool rayIntersectsLine(const Point2D& point, const Line2D& line);

    // Line vs Line
    bool lineLine(const Line2D& line1, const Line2D& line2);

    // Additional functions for other types (Vector2D, Line vs Circle, etc.) can be added similarly
}

