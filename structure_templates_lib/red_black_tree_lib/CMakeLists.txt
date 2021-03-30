cmake_minimum_required(VERSION 3.17)
project(red_black_tree_lib)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        RedBlackTree.h
        nodes/NodeImpl.h
        nodes/Node.h
        nodes/Sentinel.h
        node_util/Side.h
        nodes/SimpleFactory.h
        colors/Colored.h
        colors/RedBlack.h
        colors/Black.h
        nodes/RBNodeImpl.h
        nodes/Node.h
        node_util/NodeFinder.h
        node_util/KeyFinder.h
        node_util/PlaceToPutFinder.h
        node_util/NodePutter.h
        node_util/ConsequentFinder.h
        node_util/NodeReplacer.h
        node_util/ConsequentLiberator.h
        node_util/NodeUtility.h
        node_util/RootFinder.h
        nodes/RBSentinel.h
        nodes/RBNode.h
        nodes/NodeFactory.h
        nodes/RBFactory.h
        node_util/NodeRotator.h
        rbutil/PutPropertyRestorer.h
        rbutil/DeletePropertyRestorer.h)

set(SOURCE_FILES
        index.cpp
        node_util/Side.cpp
        colors/RedBlack.cpp
        colors/Black.cpp)

add_library(red_black_tree_lib STATIC ${HEADER_FILES} ${SOURCE_FILES})