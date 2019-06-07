cmake_minimum_required(VERSION 3.14)
project(Labo5)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(gtest)

add_executable(Labo5
        src/Customer.cpp
        src/Customer.h
        src/main.cpp
        src/Movie.cpp
        src/Movie.h
        src/MoviePrice.h
        src/MoviePrice.cpp
        src/Rental.h
        src/Rental.cpp)

add_executable(test
        test/test.cpp
        test/test.h
        test/MoviePriceTest.h
        src/Customer.cpp
        src/Customer.h
        src/Movie.cpp
        src/Movie.h
        src/MoviePrice.h
        src/MoviePrice.cpp
        src/Rental.h
        src/Rental.cpp)

target_link_libraries(test gtest gmock_main)