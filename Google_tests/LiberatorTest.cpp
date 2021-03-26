#include "gtest/gtest.h"
#include <red_black_tree_lib/ConsequentLiberator.h>
#include <red_black_tree_lib/NodeFactory.h>

TEST(LiberatorSuite, Compilation){
    auto replacer = ConsequentLiberator<int, int>(NodeFactory<int, int>::makeNode(0,0));
}

TEST(LiberatorSuite, LiberateRootWithRightChild){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto right = NodeFactory<int, int>::makeNode(7,7);
    root->setRight(right);
    right->setParent(root);
    auto liberator = ConsequentLiberator<int, int>(root);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_EQ(root, right);
    ASSERT_TRUE(right->getParent()->isNil());
}

TEST(LiberatorSuite, LiberateRootWithLeftChild){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto left = NodeFactory<int, int>::makeNode(3,3);
    root->setLeft(left);
    left->setParent(root);
    auto liberator = ConsequentLiberator<int, int>(root);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_EQ(root, left);
    ASSERT_TRUE(left->getParent()->isNil());
}

TEST(LiberatorSuite, LiberateRootChildless){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto liberator = ConsequentLiberator<int, int>(root);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_TRUE(root->isNil());
}

TEST(LiberatorSuite, LiberateLeftConsequent){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto consequent = NodeFactory<int, int>::makeNode(3,3);
    auto consequentChild = NodeFactory<int, int>::makeNode(4,4);
    root->setLeft(consequent);
    consequent->setParent(root);
    consequent->setRight(consequentChild);
    consequentChild->setParent(consequent);
    auto liberator = ConsequentLiberator<int, int>(consequent);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_EQ(root->getLeft(), consequentChild);
    ASSERT_EQ(root, consequentChild->getParent());
}

TEST(LiberatorSuite, LiberateRightConsequent){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto consequent = NodeFactory<int, int>::makeNode(8,8);
    auto consequentChild = NodeFactory<int, int>::makeNode(6,6);
    root->setRight(consequent);
    consequent->setParent(root);
    consequent->setLeft(consequentChild);
    consequentChild->setParent(consequent);
    auto liberator = ConsequentLiberator<int, int>(consequent);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_EQ(root->getRight(), consequentChild);
    ASSERT_EQ(root, consequentChild->getParent());
}

TEST(LiberatorSuite, LiberateRightChildless){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto consequent = NodeFactory<int, int>::makeNode(8,8);
    root->setRight(consequent);
    consequent->setParent(root);
    auto liberator = ConsequentLiberator<int, int>(consequent);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_TRUE(root->getRight()->isNil());
}

TEST(LiberatorSuite, LiberateLeftChildless){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto consequent = NodeFactory<int, int>::makeNode(3,3);
    root->setLeft(consequent);
    consequent->setParent(root);
    auto liberator = ConsequentLiberator<int, int>(consequent);
    liberator.free();
    root = liberator.obtainRoot();

    ASSERT_TRUE(root->getLeft()->isNil());
}