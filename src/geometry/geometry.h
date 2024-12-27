// geometry.h
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <vector>
#include <algorithm>

// Point structure
struct point {
    double x;
    double y;

    point(double x = 0, double y = 0);
};

// Vector structure
struct vector {
    double x
    double y ;

    vector(double x = 0, double y = 0);

    vector operator+(const vector& v) const;
    vector operator-(const vector& v) const;
    double dot(const vector& v) const;
    double cross(const vector& v) const;
    double magnitude() const;
    vector normalize() const;
};

// Line structure
struct line {
    double a;
    double b;
    double c;

    line(double a, double b, double c);
    line(const point& p1, const point& p2);
};

// Segment structure
struct segment {
    point p1;
    point p2;

    segment(const point& p1, const point& p2);
};

// Function declarations
bool intersect(const line& l1, const line& l2, point& intersection);
bool intersect(const segment& s1, const segment& s2);
bool on_segment(const point& p, const point& q, const point& r);
int orientation(const point& p, const point& q, const point& r);

double polygon_area(const std::vector<point>& vertices);
bool is_inside_polygon(const std::vector<point>& vertices, const point& p);

#endif // GEOMETRY_H
