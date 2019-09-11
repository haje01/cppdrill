# nlohmann json
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(${EXTERNAL_DIR}/json ../build/externals/json)

# mylib
add_library(mylib SHARED
    lib.cpp
)

target_include_directories(mylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(mylib
PRIVATE
    nlohmann_json::nlohmann_json
)

# pybind11
add_subdirectory(${EXTERNAL_DIR}/pybind11 ../build/externals/pybind11)
# Prevent `cmake __create_def` error for Visual Studio Release DLL
set(PYBIND11_LTO_CXX_FLAGS "")
pybind11_add_module(pymylib SHARED pylib.cpp)
target_include_directories(pymylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# pymylib
target_link_libraries(pymylib
PRIVATE
    mylib
)
