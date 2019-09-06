
add_executable(mylib_test test.cpp)

set(CATCH_DIR "${EXTERNAL_DIR}/Catch2")
add_subdirectory(${CATCH_DIR} ../build/externals/Catch2)
target_link_libraries(mylib_test Catch2::Catch2 mylib)

# set(CATCH_INCLUDE_DIR ${EXTERNAL_DIR}/Catch2/single_include)
# message("Catch DIR ${CATCH_INCLUDE_DIR}")
# target_link_libraries(mylib_test mylib)
# target_include_directories(mylib_test PUBLIC ${CATCH_INCLUDE_DIR})

add_test(
NAME
    test_mylib
COMMAND
    mylib_test
)