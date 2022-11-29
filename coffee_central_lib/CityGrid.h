//
// Created by misha on 11.11.2022.
//

#ifndef COFFEECENTRAL_CITYGRID_H
#define COFFEECENTRAL_CITYGRID_H


#include <array>
#include <vector>
#include <ostream>
#include "Point.h"

struct SearchResult {
    SearchResult(int64_t pointsNumber, const Point& bestPoint);

    friend std::ostream& operator<<(std::ostream& os, const SearchResult& result);

    int64_t pointsNumber;
    Point bestPoint;
};

class CityGrid {
public:
    explicit CityGrid(uint32_t width, uint32_t height);

    SearchResult findBestPoint(int64_t maxDistance);
    int64_t getCoffeeNumberForVector(Point startingPoint, int64_t maxDistance);
    void addCoffeePoint(Point point);

private:
    std::vector<std::vector<int64_t>> crossroads;
    std::vector<Point> coffeePoints;
};


#endif //COFFEECENTRAL_CITYGRID_H
