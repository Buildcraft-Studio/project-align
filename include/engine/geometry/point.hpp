#ifndef POINT_HPP
#define POINT_HPP

class point {
public:
    float x, y;

    point();
    point(float x_val, float y_val);

    float distance_to(const point& other) const;
};

#endif
