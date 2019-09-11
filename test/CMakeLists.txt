add_executable(mylib_test test.cpp)

# Catch2 for test
set(CATCH_DIR "${EXTERNAL_DIR}/Catch2")
add_subdirectory(${CATCH_DIR} ../build/externals/Catch2)
target_link_libraries(mylib_test Catch2::Catch2 mylib)

# Add test
add_test(
NAME
    test_mylib
COMMAND
    mylib_test
)