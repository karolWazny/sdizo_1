cmake_minimum_required(VERSION 3.17)
project(tree_lib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        BinaryTree.h)

set(SOURCE_FILES
        index.cpp)

add_library(tree_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})