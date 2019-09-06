cmake_minimum_required(VERSION 3.1)

project(cppdrill LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(test)
