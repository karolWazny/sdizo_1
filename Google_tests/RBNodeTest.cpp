#include "gtest/gtest.h"
#include <red_black_tree_lib/nodes/RBFactory.h>

TEST(RBNodeSuite, Compilation){
    auto node = RBFactory<int, int>().createNode(2, 2);
}

TEST(RBNodeSuite, GetContentReturnsReference){
    auto node = RBFactory<int, int>().createNode(2, 3);
    ASSERT_EQ(node->getContent(), 3);
    node->getContent()++;
    ASSERT_EQ(node->getContent(), 4);
}

TEST(RBNodesuite, GetKey){
    auto node = RBFactory<int, int>().createNode(2, 3);
    ASSERT_EQ(node->getKey(), 2);
}

TEST(RBNodesuite, GetLeftEmpty){
    auto node = RBFactory<int, int>().createNode(2, 3);
    auto child = node->getLeft();
    ASSERT_TRUE(child->isNil());
    ASSERT_TRUE((std::dynamic_pointer_cast<RBNode<int, int>>(child))->isBlack());
}

TEST(RBNodesuite, GetRightEmpty){
    auto node = RBFactory<int, int>().createNode(2, 3);
    auto child = node->getRight();
    ASSERT_TRUE(child->isNil());
    ASSERT_TRUE((std::dynamic_pointer_cast<RBNode<int, int>>(child))->isBlack());
}

TEST(RBNodesuite, GetParentEmpty){
    auto node = RBFactory<int, int>().createNode(2, 3);
    auto parent = node->getParent();
    ASSERT_TRUE(parent->isNil());
    ASSERT_TRUE((std::dynamic_pointer_cast<RBNode<int, int>>(parent))->isBlack());
}
