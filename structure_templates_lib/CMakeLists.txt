cmake_minimum_required(VERSION 3.17)
project(structure_templates_lib)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        index.cpp)

add_library(structure_templates_lib ${SOURCE_FILES})

add_subdirectory(array_lib)
add_subdirectory(binary_heap_lib)
add_subdirectory(linked_list_lib)
add_subdirectory(red_black_tree_lib)
add_subdirectory(tree_lib)

target_link_libraries(structure_templates_lib
        array_lib
        binary_heap_lib
        linked_list_lib
        red_black_tree_lib
        tree_lib
        )