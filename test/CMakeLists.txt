set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(TBB REQUIRED tbb tbbmalloc)

add_executable(test_all
    test_mylib.cpp
    test_tbb.cpp
)

target_link_libraries(test_all
    Catch2::Catch2
    ${TBB_IMPORTED_TARGETS}
    mylib
)

# add_executable(test_tbb test_tbb.cpp)
# target_include_directories(test_tbb PRIVATE ${TBB_INCLUDE_DIRS})
# target_compile_definitions(test_tbb PRIVATE ${TBB_DEFINITIONS})
# target_link_libraries(test_tbb ${TBB_LIBRARIES})
# message("TBB_INCLUDE_DIRS ${TBB_INCLUDE_DIRS}")

# Add test
add_test(
NAME
    test_all
COMMAND
    test_all
)


