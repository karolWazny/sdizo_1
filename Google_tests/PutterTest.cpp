#include "gtest/gtest.h"
#include <red_black_tree_lib/NodeFactory.h>
#include <red_black_tree_lib/NodePutter.h>

TEST(KeyFinderSuite, PutOnTheRight){
    auto node = NodeFactory<int, int>::makeNode(2,3);
    auto putter = NodePutter<int, int>(node);
    putter.put(5,4);
    ASSERT_FALSE(node->getRight()->isNil());
    ASSERT_TRUE(node->getLeft()->isNil());
    ASSERT_EQ(node->getRight()->getKey(), 5);
}

TEST(KeyFinderSuite, PutOnTheLeft){
    auto node = NodeFactory<int, int>::makeNode(2,3);
    auto putter = NodePutter<int, int>(node);
    putter.put(1,4);
    ASSERT_FALSE(node->getLeft()->isNil());
    ASSERT_TRUE(node->getRight()->isNil());
    ASSERT_EQ(node->getLeft()->getKey(), 1);
}

TEST(KeyFinderSuite, PutIntoEmptyTree){
    auto node = NodeFactory<int, int>::makeNode(2,3);
    node = node->getLeft();
    auto putter = NodePutter<int, int>(node);
    putter.put(1,4);
    node = putter.getRoot();
    ASSERT_FALSE(node->isNil());
    ASSERT_TRUE(node->getLeft()->isNil());
    ASSERT_TRUE(node->getRight()->isNil());
    ASSERT_EQ(node->getKey(), 1);
    ASSERT_EQ(node->getContent(), 4);
}
