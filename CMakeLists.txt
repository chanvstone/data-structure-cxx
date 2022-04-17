cmake_minimum_required(VERSION 3.18)
project(data_structure_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)

add_library(linear_list SHARED linear_list.h linear_list.cpp)
add_library(polynomial SHARED polynomial.h polynomial.cpp)
add_library(linked_list SHARED linked_list.h linked_list.cpp)
add_library(seqlist SHARED seqlist.h seqlist.cpp)

add_executable(test test.cpp)
target_link_libraries(seqlist linear_list)
target_link_libraries(linked_list linear_list)
target_link_libraries(test seqlist)