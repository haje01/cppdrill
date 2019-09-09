
# for Visual Studio Debug/Release Config
message("CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()

add_library(mylib SHARED
    lib.cpp
)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# set(PYBIND11_CPP_STANDARD -std=c++14)
# set(PYBIND11_PYTHON_VERSION=3.7)
add_subdirectory(${CMAKE_SOURCE_DIR}/externals/pybind11
    ../build/externals/pybind11
)
pybind11_add_module(pymylib SHARED pylib.cpp)
target_include_directories(pymylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(pymylib
PUBLIC
    mylib
)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/bin)
message("CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}")