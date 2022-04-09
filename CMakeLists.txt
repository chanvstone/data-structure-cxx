cmake_minimum_required(VERSION 3.18)
project(data_structure_cxx)

set(CMAKE_CXX_STANDARD 20)

add_executable(test test.cc)
add_library(polynomial polynomial.cc polynomial.h)
target_link_libraries(test polynomial)