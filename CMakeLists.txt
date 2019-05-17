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
        src/Rental.h)

add_executable(test
        test/test.cpp
        test/test.h
        src/Customer.cpp
        src/Customer.h
        src/Movie.cpp
        src/Movie.h
        src/Rental.h)

target_link_libraries(test gtest gmock_main)