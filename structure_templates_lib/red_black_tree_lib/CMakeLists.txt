cmake_minimum_required(VERSION 3.17)
project(red_black_tree_lib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        RedBlackTree.h
        NodeImpl.h
        Node.h
        Sentinel.h
        NodeFinder.h
        KeyFinder.h
        PlaceToPutFinder.h
        NodePutter.h
        RootFinder.h
        ConsequentFinder.h
        Side.h
        NodeReplacer.h
        NodeFactory.h
        ConsequentLiberator.h
        NodeUtility.h
        Colored.h
        RedBlack.h
        Black.h)

set(SOURCE_FILES
        index.cpp
        Side.cpp
        RedBlack.cpp
        Black.cpp)

add_library(red_black_tree_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})