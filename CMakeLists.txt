cmake_minimum_required(VERSION 3.17)
project(sdizo_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdizo_1 main.cpp)

include_directories(structure_templates_lib)
add_subdirectory(structure_templates_lib)

target_link_libraries(sdizo_1 structure_templates_lib)

add_subdirectory(Google_tests)