#
# mylib
#
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

#
# pymylib
#
pybind11_add_module(pymylib SHARED pylib.cpp)
target_include_directories(pymylib
PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(pymylib
PRIVATE
    mylib
)

# prevent script error of __create_def in Release mode (remove $<$<NOT:$<CONFIG:Debug>>:/GL>)
set_target_properties(pymylib PROPERTIES COMPILE_OPTIONS  "/W4;$<$<COMPILE_LANGUAGE:CXX>:>;/bigobj;$<$<NOT:$<CONFIG:Debug>>:$<$<COMPILE_LANGUAGE:CXX>:/MP>>")
