cmake_minimum_required(VERSION 3.18)
project(data_structure_cxx)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_executable(test test.cc)
add_library(polynomial polynomial.cc polynomial.h)
add_library(linked_list linked_list.h linked_list.cc)
target_link_libraries(test linked_list)