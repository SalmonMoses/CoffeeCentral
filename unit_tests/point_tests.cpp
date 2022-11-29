//
// Created by misha on 11.11.2022.
//

#include "doctest.h"
#include "../coffee_central_lib/Point.h"

TEST_CASE("Point") {
    SUBCASE("Finding distance") {
        Point a(5, 6);
        Point b(4, 7);
        CHECK_EQ(2, a.distance(b));
    }
}