//
// Created by misha on 11.11.2022.
//

#ifndef COFFEECENTRAL_POINT_H
#define COFFEECENTRAL_POINT_H

#include <cstdint>
#include <ostream>

struct Point {
    int64_t x;
    int64_t y;

    Point(int64_t x, int64_t y);

    [[nodiscard]] int64_t distance(Point another);

    bool operator==(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif //COFFEECENTRAL_POINT_H
