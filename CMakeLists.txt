cmake_minimum_required(VERSION 3.14)
project(leetcode C)
link_directories(./include)
include_directories(./)
    set(CMAKE_C_STANDARD 99)
aux_source_directory(./src srcs)
add_executable(leetcode ${srcs})

add_subdirectory("divisorGame")