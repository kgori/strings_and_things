cmake_minimum_required(VERSION 3.20)
project(string_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_library(string_algorithms
        string_algorithms/include/suffix_array.h
        string_algorithms/src/suffix_array.cpp)

target_include_directories(string_algorithms PRIVATE ${PROJECT_SOURCE_DIR}/string_algorithms/include)

add_executable(main main.cpp)
target_link_libraries(main string_algorithms)
