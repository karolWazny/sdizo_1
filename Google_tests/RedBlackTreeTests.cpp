#include "gtest/gtest.h"
#include <red_black_tree_lib/RedBlackTree.h>

TEST(RedBlackTestSuite, Compilation){
    auto tree = RedBlackTree<int, int>();
}

TEST(RedBlackTestSuite, PutContains){
    auto tree = RedBlackTree<int, int>();
    ASSERT_FALSE(tree.containsKey(4));
    tree.put(4, 5);
    ASSERT_TRUE(tree.containsKey(4));
    ASSERT_FALSE(tree.containsKey(5));
    tree.put(5, 5);
    ASSERT_TRUE(tree.containsKey(5));
    ASSERT_TRUE(tree.containsKey(4));
}

TEST(RedBlackTestSuite, RemoveRoot){
    auto tree = RedBlackTree<int, int>();
    tree.put(23, 23);
    tree.put(50, 50);
    tree.put(10, 10);
    tree.put(60, 60);
    tree.put(40,40);
    ASSERT_TRUE(tree.containsKey(23));
    ASSERT_TRUE(tree.containsKey(50));
    ASSERT_TRUE(tree.containsKey(10));
    ASSERT_TRUE(tree.containsKey(60));
    ASSERT_TRUE(tree.containsKey(40));
    tree.removeKey(23);
    ASSERT_FALSE(tree.containsKey(23));
    ASSERT_TRUE(tree.containsKey(50));
    ASSERT_TRUE(tree.containsKey(10));
    ASSERT_TRUE(tree.containsKey(60));
    ASSERT_TRUE(tree.containsKey(40));
}