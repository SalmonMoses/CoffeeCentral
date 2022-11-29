//
// Created by misha on 11.11.2022.
//

#include "doctest.h"
#include "../coffee_central_lib/CityGrid.h"

TEST_CASE("Grid") {
    CityGrid grid(10, 10);

    SUBCASE("Find coffees in ranges") {
        grid.addCoffeePoint(Point(3, 2));
        grid.addCoffeePoint(Point(8, 6));
        grid.addCoffeePoint(Point(5, 1));
        CHECK_EQ(1, grid.getCoffeeNumberForVector(Point(5, 0), 1));
        CHECK_EQ(2, grid.getCoffeeNumberForVector(Point(5, 0), 4));
    }

    SUBCASE("Find best place for point") {
        grid.addCoffeePoint(Point(1, 1));
        grid.addCoffeePoint(Point(1, 2));
        grid.addCoffeePoint(Point(3, 3));
        grid.addCoffeePoint(Point(4, 4));
        grid.addCoffeePoint(Point(2, 4));
        const SearchResult result = grid.findBestPoint(1);
        CHECK_EQ(result.bestPoint, Point(3, 4));
        CHECK_EQ(result.pointsNumber, 3);
    }
}