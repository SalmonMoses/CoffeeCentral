#include <iostream>
#include <fstream>
#include <string>
#include "coffee_central_lib/CityGrid.h"

bool runCase(std::ifstream& ifStream, std::vector<SearchResult>& results) {
    int64_t gridX, gridY;
    ifStream >> gridX >> gridY;
    int64_t coffeePointsNumber;
    ifStream >> coffeePointsNumber;
    int64_t queriesNumber;
    ifStream >> queriesNumber;
    if (gridX == 0 && gridY == 0 && coffeePointsNumber == 0 && queriesNumber == 0) {
        return false;
    }
    CityGrid cityGrid(gridX, gridY);
    for (int64_t i = 0; i < coffeePointsNumber; ++i) {
        int64_t x, y;
        ifStream >> x >> y;
        cityGrid.addCoffeePoint(Point(x - 1, y - 1));
    }
    for (int64_t i = 0; i < queriesNumber; ++i) {
        int64_t maxDistance;
        ifStream >> maxDistance;
        results.emplace_back(cityGrid.findBestPoint(maxDistance));
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::ifstream ifStream(argv[1]);
    uint64_t counter = 1;
    bool needsExit;
    std::vector<SearchResult> resultsBuffer;
    do {
        resultsBuffer.clear();
        needsExit = !runCase(ifStream, resultsBuffer);
        if (!needsExit) {
            std::cout << "Case " << counter << ":" << std::endl;
            for (const SearchResult& result: resultsBuffer) {
                std::cout << result << std::endl;
            }
            counter++;
            std::cout << std::endl;
        }
    } while (!needsExit);
    return 0;
}
