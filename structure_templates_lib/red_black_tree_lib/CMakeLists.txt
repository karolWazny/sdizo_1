cmake_minimum_required(VERSION 3.17)
project(red_black_tree_lib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        RedBlackTree.h
        NodeImpl.h
        Compare.h
        Node.h
        Sentinel.h
        NodeFinder.h
        KeyFinder.h)

set(SOURCE_FILES
        index.cpp)

add_library(red_black_tree_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})