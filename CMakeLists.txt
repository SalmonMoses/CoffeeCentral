cmake_minimum_required(VERSION 3.23)
project(CoffeeCentral)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DTEST")

include_directories(include)
add_subdirectory(unit_tests)
add_subdirectory(coffee_central_lib)

add_executable(CoffeeCentral main.cpp)
target_link_libraries(CoffeeCentral CoffeeCentralLib)
