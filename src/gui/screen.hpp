#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <vector>
#include <algorithm>

// Point structure
struct Point {
    double x, y;

    Point(double x = 0, double y = 0);
};

// Vector structure
struct Vector {
    double x, y;

    Vector(double x = 0, double y = 0);

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    double dot(const Vector& v) const;
    double cross(const Vector& v) const;
    double magnitude() const;
    Vector normalize() const;
};

// Line structure
struct Line {
    double A, B, C;

    Line(double A, double B, double C);
    Line(const Point& p1, const Point& p2);
};

// Segment structure
struct Segment {
    Point p1, p2;

    Segment(const Point& p1, const Point& p2);
};

// Function declarations
bool intersect(const Line& l1, const Line& l2, Point& intersection);
bool intersect(const Segment& s1, const Segment& s2);
bool onSegment(const Point& p, const Point& q, const Point& r);
int orientation(const Point& p, const Point& q, const Point& r);

double polygonArea(const std::vector<Point>& vertices);
bool isInsidePolygon(const std::vector<Point>& vertices, const Point& p);

#endif // GEOMETRY_H
