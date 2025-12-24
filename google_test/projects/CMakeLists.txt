cmake_minimum_required(VERSION 3.2...3.27.5)

project(kmms_prog25)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(sort_lib "")

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(bubble_sort)

