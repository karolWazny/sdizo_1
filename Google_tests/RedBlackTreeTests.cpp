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
    tree.insert(3);
    tree.insert(2);
    tree.insert(56);
    tree.insert(10);
    tree.insert(18);
    tree.insert(19);
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

TEST(RedBlackTestSuite, RemoveSizeUpdate){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    tree.insert(5);
    tree.insert(4);
    tree.insert(56);
    tree.insert(10);
    tree.insert(18);
    tree.insert(6);
    ASSERT_EQ(tree.getSize(), 7);
    tree.remove(4);
    ASSERT_EQ(tree.getSize(), 6);
}

TEST(RedBlackTestSuite, RemoveContainsUpdate){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    tree.insert(4);
    tree.insert(56);
    tree.insert(10);
    tree.insert(18);
    tree.insert(6);
    ASSERT_TRUE(tree.contains(6));
    tree.remove(6);
    ASSERT_FALSE(tree.contains(6));
}

TEST(RedBlackTestSuite, Remove){
    auto tree = RedBlackTree<int>();
    tree.insert(5);
    tree.insert(4);
    tree.insert(56);
    tree.remove(5);
    ASSERT_TRUE(tree.contains(4));
    ASSERT_TRUE(tree.contains(56));
}