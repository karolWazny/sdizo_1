#include "gtest/gtest.h"
#include <red_black_tree_lib/nodes/RBFactory.h>
#include <red_black_tree_lib/RBRemover.h>

TEST(RemoverSuite, SimpleCaseRedSuccessor){
    auto factory = RBFactory<int, int>();
    auto root = rbcast(factory.makeNode(10, 10));
    auto nodeToRemove = rbcast(factory.makeNode(20, 20));
    auto right = rbcast(factory.makeNode(30, 30));
    auto successor = rbcast(factory.makeNode(25, 25));
    auto successorChild = rbcast(factory.makeNode(28, 28));

    root->setRight(nodeToRemove);
    nodeToRemove->setParent(root);
    root->paintBlack();

    nodeToRemove->setRight(right);
    right->setParent(nodeToRemove);
    nodeToRemove->paintBlack();

    right->setLeft(successor);
    successor->setParent(right);
    right->paintBlack();

    successor->setRight(successorChild);
    successorChild->setParent(successor);

    auto remover = RBRemover<int, int>(root);
    remover.remove(nodeToRemove->getKey());

    ASSERT_EQ(root->getRight(), successor);
    ASSERT_EQ(root, successor->getParent());
    ASSERT_TRUE(successor->isBlack());
}