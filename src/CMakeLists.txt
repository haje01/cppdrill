
add_library(mylib SHARED
    lib.cpp
)

# add_library(pymylib SHARED
#     pylib.cc
# )
# target_link_libraries(pymylib PUBLIC mylib)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

set(PYBIND11_CPP_STANDARD -std=c++14)
set(PYBIND11_PYTHON_VERSION=3.7)
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