
add_library(mylib SHARED
    lib.cpp
)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)