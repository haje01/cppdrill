
enable_testing()

add_executable(mylib_test test.cpp)
target_link_libraries(mylib_test mylib)