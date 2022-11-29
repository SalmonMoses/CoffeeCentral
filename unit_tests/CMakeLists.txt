project(Tests)

include_directories(../include)
include_directories(../coffee_central_lib)

add_executable(Tests grid_tests.cpp point_tests.cpp main.cpp)
target_link_libraries(Tests CoffeeCentralLib)