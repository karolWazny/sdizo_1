#include "gtest/gtest.h"
#include <red_black_tree_lib/Node.h>

TEST(NodeSuite, Compilation){
    auto node = Node<int, int>(2, 3);
}

TEST(NodeSuite, GetContentReturnsReference){
    auto node = Node<int, int>(2, 3);
    ASSERT_EQ(node.getContent(), 3);
    node.getContent()++;
    ASSERT_EQ(node.getContent(), 4);
}

TEST(Nodesuite, GetKey){
    auto node = Node<int, int>(2, 3);
    ASSERT_EQ(node.getKey(), 2);
}