//
// Created by misha on 11.11.2022.
//

#include "CityGrid.h"

SearchResult::SearchResult(int64_t pointsNumber, const Point& bestPoint) : pointsNumber(pointsNumber),
                                                                           bestPoint(bestPoint) {}

std::ostream& operator<<(std::ostream& os, const SearchResult& result) {
    os << result.pointsNumber << " " << result.bestPoint;
    return os;
}

CityGrid::CityGrid(uint32_t width, uint32_t height) : crossroads(height) {
    for (auto& row: crossroads) {
        row = std::vector<int64_t>(width);
    }
}

SearchResult CityGrid::findBestPoint(int64_t maxDistance) {
    int64_t bestX, bestY = 0;
    int64_t coffeesInBestPoint = std::numeric_limits<int64_t>::min();
    for (int y = 0; y < crossroads.size(); ++y) {
        for (int x = 0; x < crossroads[y].size(); ++x) {
            crossroads[y][x] = getCoffeeNumberForVector(Point(x, y), maxDistance);
            if (crossroads[y][x] > coffeesInBestPoint) {
                bestX = x;
                bestY = y;
                coffeesInBestPoint = crossroads[y][x];
            }
        }
    }
    SearchResult result(coffeesInBestPoint, Point(bestX, bestY));
    return result;
}

int64_t CityGrid::getCoffeeNumberForVector(Point startingPoint, int64_t maxDistance) {
    int64_t result = 0;
    for (auto& coffeePoint: coffeePoints) {
        int64_t distance = startingPoint.distance(coffeePoint);
        if (distance <= maxDistance) {
            result++;
        }
    }
    return result;
}

void CityGrid::addCoffeePoint(Point point) {
    coffeePoints.push_back(point);
}
