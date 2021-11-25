cmake_minimum_required(VERSION 3.0)

set(myproject "library")

project(${myproject})

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} src.cpp Fiction.cpp Fiction.hpp Book.hpp Book.cpp TravelGuide.hpp TravelGuide.cpp)