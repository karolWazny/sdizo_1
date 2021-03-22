#include "gtest/gtest.h"
#include <red_black_tree_lib/NodeImpl.h>
#include <red_black_tree_lib/KeyFinder.h>

TEST(KeyFinderSuite, KeyFoundInInitialNode){
    auto node = NodePointer<int, int>(new NodeImpl<int, int>(2,3));
    auto finder = KeyFinder<int, int>(node);
    finder.setDesiredKey(2);
    ASSERT_FALSE(finder.nodeFound());
    finder.find();
    ASSERT_TRUE(finder.nodeFound());
    ASSERT_EQ(finder.getFound(), node);
}

TEST(KeyFinderSuite, KeyNotFoundInSingleNode){
    auto node = NodePointer<int, int>(new NodeImpl<int, int>(2,3));
    auto finder = KeyFinder<int, int>(node);
    finder.setDesiredKey(3);
    ASSERT_FALSE(finder.nodeFound());
    finder.find();
    ASSERT_FALSE(finder.nodeFound());
    finder.getFound()->getContent();
}

TEST(KeyFinderSuite, KeyFoundInLeftNode){
    auto parent = NodePointer<int, int>(new NodeImpl<int, int>(5,3));
    auto left = NodePointer<int, int>(new NodeImpl<int, int>(2,3));
    auto right = NodePointer<int, int>(new NodeImpl<int, int>(8,3));
    parent->setLeft(left);
    parent->setRight(right);
    auto finder = KeyFinder<int, int>(parent);
    finder.setDesiredKey(2);
    ASSERT_FALSE(finder.nodeFound());
    finder.find();
    ASSERT_TRUE(finder.nodeFound());
    ASSERT_EQ(finder.getFound(), left);
}

TEST(KeyFinderSuite, KeyFoundInRightNode){
    auto parent = NodePointer<int, int>(new NodeImpl<int, int>(5,3));
    auto left = NodePointer<int, int>(new NodeImpl<int, int>(2,3));
    auto right = NodePointer<int, int>(new NodeImpl<int, int>(8,3));
    parent->setLeft(left);
    parent->setRight(right);
    auto finder = KeyFinder<int, int>(parent);
    finder.setDesiredKey(8);
    ASSERT_FALSE(finder.nodeFound());
    finder.find();
    ASSERT_TRUE(finder.nodeFound());
    ASSERT_EQ(finder.getFound(), right);
}