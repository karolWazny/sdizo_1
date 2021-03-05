#include "gtest/gtest.h"
#include <red_black_tree_lib/RedBlackTree.h>

TEST(RedBlackTestSuite, Compilation){
    auto tree = RedBlackTree<int>();
    ASSERT_EQ(tree.getSize(), 0);
}

TEST(RedBlackTestSuite, InsertCompilation){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
}

TEST(RedBlackTestSuite, InsertSizeUpdate){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    ASSERT_EQ(tree.getSize(), 1);
    tree.insert(6);
    ASSERT_EQ(tree.getSize(), 2);
}

TEST(RedBlackTestSuite, ContainsFalse){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    tree.insert(4);
    tree.insert(56);
    tree.insert(10);
    tree.insert(18);
    ASSERT_FALSE(tree.contains(6));
}

TEST(RedBlackTestSuite, ContainsTrue){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    tree.insert(4);
    tree.insert(56);
    tree.insert(10);
    tree.insert(18);
    tree.insert(6);
    ASSERT_TRUE(tree.contains(6));
}