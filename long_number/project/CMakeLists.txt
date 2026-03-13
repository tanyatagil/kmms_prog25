cmake_minimum_required(VERSION 3.10)
project(long_numbers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LONG_NUMBER_LIB "long_number_lib")
add_subdirectory(googletest)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
