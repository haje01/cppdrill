
# mylib
add_library(mylib SHARED
    lib.cpp
)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# pybind11
add_subdirectory(${CMAKE_SOURCE_DIR}/externals/pybind11
    ../build/externals/pybind11
)
# Prevent `cmake __create_def` error for Visual Studio Release DLL
set(PYBIND11_LTO_CXX_FLAGS "")
pybind11_add_module(pymylib SHARED pylib.cpp)
target_include_directories(pymylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# pymylib
target_link_libraries(pymylib
PUBLIC
    mylib
)
