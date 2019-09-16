cmake_minimum_required(VERSION 3.1)

project(cppdrill LANGUAGES CXX VERSION 0.0.1)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)

add_subdirectory(externals)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
