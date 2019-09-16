set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(mylib SHARED
    lib.cpp
)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
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