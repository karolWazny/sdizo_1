#include "gtest/gtest.h"
#include <red_black_tree_lib/NodeReplacer.h>
#include <red_black_tree_lib/NodeFactory.h>

TEST(NodeReplacerSuite, Compilation){
    auto replacer = NodeReplacer<int, int>(NodeFactory<int, int>::makeNode(0,0));
}

TEST(NodeReplacerSuite, OuterLeftReplacement){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto left = NodeFactory<int, int>::makeNode(3,3);
    auto right = NodeFactory<int, int>::makeNode(7,7);
    root->setLeft(left);
    root->setRight(right);
    left->setParent(root);
    right->setParent(root);
    auto replacement = NodeFactory<int, int>::makeNode(2,2);
    auto replacer = NodeReplacer<int, int>(left);
    replacer.replaceWithNode(replacement);
    root = replacer.obtainRoot();

    ASSERT_EQ(root->getLeft(), replacement);
    ASSERT_EQ(root, replacement->getParent());
}

TEST(NodeReplacerSuite, OuterRightReplacement){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto left = NodeFactory<int, int>::makeNode(3,3);
    auto right = NodeFactory<int, int>::makeNode(7,7);
    root->setLeft(left);
    root->setRight(right);
    left->setParent(root);
    right->setParent(root);
    auto replacement = NodeFactory<int, int>::makeNode(8,8);
    auto replacer = NodeReplacer<int, int>(right);
    replacer.replaceWithNode(replacement);
    root = replacer.obtainRoot();

    ASSERT_EQ(root->getRight(), replacement);
    ASSERT_EQ(root, replacement->getParent());
}

TEST(NodeReplacerSuite, InnerLeftReplacement){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto node = NodeFactory<int, int>::makeNode(3,3);
    auto left = NodeFactory<int, int>::makeNode(1,1);
    auto right = NodeFactory<int, int>::makeNode(4,4);
    root->setLeft(node);
    node->setLeft(left);
    node->setRight(right);
    node->setParent(root);
    left->setParent(node);
    right->setParent(node);
    auto replacement = NodeFactory<int, int>::makeNode(2,2);
    auto replacer = NodeReplacer<int, int>(node);
    replacer.replaceWithNode(replacement);
    root = replacer.obtainRoot();

    ASSERT_EQ(root->getLeft(), replacement);
    ASSERT_EQ(root, replacement->getParent());
    ASSERT_EQ(left, replacement->getLeft());
    ASSERT_EQ(right, replacement->getRight());
    ASSERT_EQ(left->getParent(), replacement);
    ASSERT_EQ(right->getParent(), replacement);
}

TEST(NodeReplacerSuite, InnerRightReplacement){
    auto root = NodeFactory<int, int>::makeNode(0,0);
    auto node = NodeFactory<int, int>::makeNode(3,3);
    auto left = NodeFactory<int, int>::makeNode(1,1);
    auto right = NodeFactory<int, int>::makeNode(4,4);
    root->setRight(node);
    node->setLeft(left);
    node->setRight(right);
    node->setParent(root);
    left->setParent(node);
    right->setParent(node);
    auto replacement = NodeFactory<int, int>::makeNode(2,2);
    auto replacer = NodeReplacer<int, int>(node);
    replacer.replaceWithNode(replacement);

    ASSERT_EQ(root->getRight(), replacement);
    ASSERT_EQ(root, replacement->getParent());
    ASSERT_EQ(left, replacement->getLeft());
    ASSERT_EQ(right, replacement->getRight());
    ASSERT_EQ(left->getParent(), replacement);
    ASSERT_EQ(right->getParent(), replacement);
}

TEST(NodeReplacerSuite, RootReplacement){
    auto root = NodeFactory<int, int>::makeNode(5,5);
    auto left = NodeFactory<int, int>::makeNode(3,3);
    auto right = NodeFactory<int, int>::makeNode(7,7);
    root->setLeft(left);
    root->setRight(right);
    left->setParent(root);
    right->setParent(root);
    auto replacement = NodeFactory<int, int>::makeNode(6,6);
    auto replacer = NodeReplacer<int, int>(root);
    replacer.replaceWithNode(replacement);
    root = replacer.obtainRoot();

    ASSERT_EQ(root, replacement);
    ASSERT_EQ(root->getRight(), right);
    ASSERT_EQ(replacement->getRight(), right);
    ASSERT_EQ(root->getLeft(), left);
    ASSERT_EQ(replacement->getLeft(), left);
    ASSERT_EQ(left->getParent(), replacement);
    ASSERT_EQ(right->getParent(), replacement);
}