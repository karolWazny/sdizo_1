cmake_minimum_required(VERSION 3.17)
project(red_black_tree_lib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        RedBlackTree.h
        RedBlackNodeImpl.h
        RedBlackNode.h
        RedBlackSentinel.h
        RedBlackRotator.h
        RedBlackPropertyRestorer.h)

set(SOURCE_FILES
        index.cpp)

add_library(red_black_tree_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})