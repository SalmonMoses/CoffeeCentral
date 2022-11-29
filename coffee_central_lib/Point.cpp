//
// Created by misha on 11.11.2022.
//
#include <cmath>

#include "Point.h"


Point::Point(int64_t x, int64_t y) : x(x), y(y) {}

int64_t Point::distance(Point another) {
    return std::abs(x - another.x) + std::abs(y - another.y);
}

bool Point::operator==(const Point& rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point& rhs) const {
    return !(rhs == *this);
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x + 1 << "," << point.y + 1 << ")";
    return os;
}
