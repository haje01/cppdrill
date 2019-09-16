cmake_minimum_required(VERSION 3.4)

project(cppdrill LANGUAGES CXX VERSION 0.0.1)

if (MSVC)
    add_compile_options(/W4)
    set(CMAKE_DEBUG_POSTFIX _d)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
    set(CMAKE_DEBUG_POSTFIX d)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/externals)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
find_package(PythonInterp 3)

add_subdirectory(externals)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
