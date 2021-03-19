#include "gtest/gtest.h"
#include <red_black_tree_lib/RedBlackTree.h>

TEST(RedBlackTestSuite, Compilation){
    auto tree = RedBlackTree<int, int>();
}

/*TEST(RedBlackTestSuite, PutContainsTrue){
    auto tree = RedBlackTree<int, int>();
    ASSERT_FALSE(tree.containsKey(4));
    ASSERT_FALSE(tree.containsValue(4));
    tree.put(4, 5);
    ASSERT_TRUE(tree.containsKey(4));
    ASSERT_TRUE(tree.containsValue(4));
}*/
