cmake_minimum_required(VERSION 3.1)

set(myproject "library")

project(${myproject})

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} src.cpp Fiction.cpp Fiction.hpp Book.hpp Book.cpp TravelGuide.hpp TravelGuide.cpp BookBuy.hpp BookBuy.cpp BookRent.cpp BookRent.hpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${myproject} PRIVATE Threads::Threads)
