// geometry.cpp
#include "geometry.h"

// Point
point::point(double x, double y) : x(x), y(y) {}

// Vector
vector::vector(double x, double y) : x(x), y(y) {}

vector vector::operator+(const vector& v) const {
    return {x + v.x, y + v.y};
}

vector vector::operator-(const vector& v) const {
    return {x - v.x, y - v.y};
}

double vector::dot(const vector& v) const {
    return x * v.x + y * v.y;
}

double vector::cross(const vector& v) const {
    return x * v.y - y * v.x;
}

double vector::magnitude() const {
    return std::sqrt(x * x + y * y);
}

vector vector::normalize() const {
    double mag = magnitude();
    return {x / mag, y / mag};
}

// Line
line::line(double a, double b, double c) : a(a), b(b), c(c) {}

line::line(const point& p1, const point& p2) {
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = a * p1.x + b * p1.y;
}

// Segment
segment::segment(const point& p1, const point& p2) : p1(p1), p2(p2) {}

// Intersect lines
bool intersect(const line& l1, const line& l2, point& intersection) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (std::abs(det) < 1e-9) return false; // Parallel lines

    intersection.x = (l2.b * l1.c - l1.b * l2.c) / det;
    intersection.y = (l1.a * l2.c - l2.a * l1.c) / det;
    return true;
}

// Orientation
int orientation(const point& p, const point& q, const point& r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (std::abs(val) < 1e-9) return 0; // Collinear
    return (val > 0) ? 1 : 2;           // Clockwise or Counterclockwise
}

// On segment
bool on_segment(const point& p, const point& q, const point& r) {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y);
}

// Intersect segments
bool intersect(const segment& s1, const segment& s2) {
    point p1 = s1.p1, q1 = s1.p2, p2 = s2.p1, q2 = s2.p2;
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special cases
    if (o1 == 0 && on_segment(p1, p2, q1)) return true;
    if (o2 == 0 && on_segment(p1, q2, q1)) return true;
    if (o3 == 0 && on_segment(p2, p1, q2)) return true;
    if (o4 == 0 && on_segment(p2, q1, q2)) return true;

    return false;
}

// Polygon area
double polygon_area(const std::vector<point>& vertices) {
    double area = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        area += vertices[i].x * vertices[(i + 1) % n].y;
        area -= vertices[i].y * vertices[(i + 1) % n].x;
    }
    return std::abs(area) / 2.0;
}

// Point inside polygon
bool is_inside_polygon(const std::vector<point>& vertices, const point& p) {
    int n = vertices.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((vertices[i].y > p.y) != (vertices[j].y > p.y)) &&
            (p.x < (vertices[j].x - vertices[i].x) * (p.y - vertices[i].y) /
             (vertices[j].y - vertices[i].y) + vertices[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}
