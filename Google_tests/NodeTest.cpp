#include "gtest/gtest.h"
#include <red_black_tree_lib/NodeImpl.h>

TEST(NodeSuite, Compilation){
    auto node = NodeImpl<int, int>(2, 3);
}

TEST(NodeSuite, GetContentReturnsReference){
    auto node = NodeImpl<int, int>(2, 3);
    ASSERT_EQ(node.getContent(), 3);
    node.getContent()++;
    ASSERT_EQ(node.getContent(), 4);
}

TEST(Nodesuite, GetKey){
    auto node = NodeImpl<int, int>(2, 3);
    ASSERT_EQ(node.getKey(), 2);
}

TEST(Nodesuite, GetLeftEmpty){
    auto node = NodeImpl<int, int>(2, 3);
    auto child = node.getLeft();
    ASSERT_TRUE(child->isNil());
}