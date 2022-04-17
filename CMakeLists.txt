cmake_minimum_required(VERSION 3.18)
project(data_structure_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(linear_list linear_list.h linear_list.cpp)
add_library(polynomial polynomial.h polynomial.cpp)
add_library(linked_list linked_list.h linked_list.cpp)
add_library(seqlist seqlist.h seqlist.cpp)

add_executable(test test.cpp)
target_link_libraries(seqlist linear_list)
target_link_libraries(linked_list linear_list)
target_link_libraries(test seqlist)