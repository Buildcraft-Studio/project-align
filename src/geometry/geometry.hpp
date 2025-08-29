#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <cmath>
#include <iostream>
#include <vector>

namespace geometry
{
    class point
    {
    private:
        float x;
        float y;
    public:
        point() : x(0), y(0) {}
        point(float x, float y) : x(x), y(y) {}
        float getX() const { return x; }
        float getY() const { return y; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
        void setXY(float x, float y) { this->x = x; this->y = y; }
    };

    class line
    {
    private:
        point p1;
        point p2;
    public:
        line() : p1(), p2() {}
        line(const point& a, const point& b) : p1(a), p2(b) {}
        point getP1() const { return p1; }
        point getP2() const { return p2; }
        void setP1(const point& a) { p1 = a; }
        void setP2(const point& b) { p2 = b; }
    };

    class circle
    {
    private:
        point center;
        float radius;
    public:
        circle() : center(), radius(0) {}
        circle(const point& c, float r) : center(c), radius(r) {}
        point getCenter() const { return center; }
        float getRadius() const { return radius; }
        void setCenter(const point& c) { center = c; }
        void setRadius(float r) { radius = r; }
    };

    class rectangle
    {
    private:
        point topLeft;
        float width;
        float height;
    public:
        rectangle() : topLeft(), width(0), height(0) {}
        rectangle(const point& tl, float w, float h) : topLeft(tl), width(w), height(h) {}
        point getTopLeft() const { return topLeft; }
        float getWidth() const { return width; }
        float getHeight() const { return height; }
        void setTopLeft(const point& tl) { topLeft = tl; }
        void setWidth(float w) { width = w; }
        void setHeight(float h) { height = h; }
    };

    class polygon
    {
    private:
        std::vector<point> vertices;
    public:
        polygon() : vertices() {}
        polygon(const std::vector<point>& pts) : vertices(pts) {}
        const std::vector<point>& getVertices() const { return vertices; }
        void addVertex(const point& p) { vertices.push_back(p); }
        void setVertices(const std::vector<point>& pts) { vertices = pts; }
    };
}

#endif // GEOMETRY_HPP