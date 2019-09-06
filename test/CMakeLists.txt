
add_executable(mylib_test test.cpp)
target_link_libraries(mylib_test mylib)

add_test(mylib mylib_test)