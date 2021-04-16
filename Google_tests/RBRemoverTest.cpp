#include "gtest/gtest.h"
#include <trees_lib/nodes/RBFactory.h>
#include <trees_lib/RBRemover.h>

TEST(RemoverSuite, SimpleCaseRedSuccessor){
    auto factory = RBFactory<int>();
    auto root = rbcast(factory.makeNode(10));
    auto nodeToRemove = rbcast(factory.makeNode(20));
    auto right = rbcast(factory.makeNode(30));
    auto successor = rbcast(factory.makeNode(25));
    auto successorChild = rbcast(factory.makeNode(28));

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

    auto remover = RBRemover<int>(root);
    remover.remove(nodeToRemove->getKey());

    ASSERT_EQ(root->getRight(), successor);
    ASSERT_EQ(root, successor->getParent());
    ASSERT_TRUE(successor->isBlack());
}