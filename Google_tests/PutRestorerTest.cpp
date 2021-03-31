#include "gtest/gtest.h"
#include <red_black_tree_lib/nodes/RBFactory.h>
#include <red_black_tree_lib/rbutil/PutPropertyRestorer.h>

TEST(PutRestorerSuite, Compilation){
    auto restorer = PutPropertyRestorer<int, int>();
}

TEST(PutRestorerSuite, BlackParentAddedIsLeft){
    auto parent = std::dynamic_pointer_cast<RBNode<int, int>>(RBFactory<int, int>().createNode(5,5));
    auto child = std::dynamic_pointer_cast<RBNode<int, int>>(RBFactory<int, int>().createNode(3,3));

    parent->paintBlack();
    child->paintRed();

    parent->setLeft(child);
    child->setParent(parent);

    auto restorer = PutPropertyRestorer<int, int>();

    restorer.restoreFrom(child);

    auto root = restorer.obtainRoot();

    ASSERT_EQ(root, parent);
    ASSERT_EQ(parent->getLeft(), child);
    ASSERT_EQ(parent, child->getParent());
}

TEST(PutRestorerSuite, BlackParentAddedIsRight){
    auto parent = std::dynamic_pointer_cast<RBNode<int, int>>(RBFactory<int, int>().createNode(5,5));
    auto child = std::dynamic_pointer_cast<RBNode<int, int>>(RBFactory<int, int>().createNode(8,8));

    parent->paintBlack();
    child->paintRed();

    parent->setRight(child);
    child->setParent(parent);

    auto restorer = PutPropertyRestorer<int, int>();

    restorer.restoreFrom(child);

    auto root = restorer.obtainRoot();

    ASSERT_EQ(root, parent);
    ASSERT_EQ(parent->getRight(), child);
    ASSERT_EQ(parent, child->getParent());
}

TEST(PutRestorerSuite, ParentIsLeftUncleIsRed){
    auto grand = rbcast(RBFactory<int, int>().createNode(7,7));
    auto parent = rbcast(RBFactory<int, int>().createNode(5,5));
    auto uncle = rbcast(RBFactory<int, int>().createNode(8,8));
    auto child = rbcast(RBFactory<int, int>().createNode(6,6));

    Side parentSide = Side::LEFT;

    grand->setSide(parent, parentSide);
    parent->setParent(grand);

    grand->setSide(uncle, !parentSide);
    uncle->setParent(grand);

    parent->setRight(child);
    child->setParent(parent);

    grand->paintBlack();
    parent->paintRed();
    uncle->paintRed();
    child->paintRed();

    auto restorer = PutPropertyRestorer<int, int>();
    restorer.restoreFrom(child);

    auto root = restorer.obtainRoot();

    ASSERT_EQ(root, grand);

    ASSERT_EQ(grand->get(parentSide), parent);
    ASSERT_EQ(grand, parent->getParent());

    ASSERT_EQ(grand->get(!parentSide), uncle);
    ASSERT_EQ(grand, uncle->getParent());

    ASSERT_EQ(parent->getRight(), child);
    ASSERT_EQ(parent, child->getParent());

    ASSERT_TRUE(parent->isBlack());
    ASSERT_TRUE(uncle->isBlack());
    ASSERT_TRUE(grand->isRed());
    ASSERT_TRUE(child->isRed());

}

TEST(PutRestorerSuite, ParentIsRightUncleIsRed){
    auto grand = rbcast(RBFactory<int, int>().createNode(7,7));
    auto parent = rbcast(RBFactory<int, int>().createNode(8,8));
    auto uncle = rbcast(RBFactory<int, int>().createNode(4,4));
    auto child = rbcast(RBFactory<int, int>().createNode(9,9));

    Side parentSide = Side::RIGHT;

    grand->setSide(parent, parentSide);
    parent->setParent(grand);

    grand->setSide(uncle, !parentSide);
    uncle->setParent(grand);

    parent->setRight(child);
    child->setParent(parent);

    grand->paintBlack();
    parent->paintRed();
    uncle->paintRed();
    child->paintRed();

    auto restorer = PutPropertyRestorer<int, int>();
    restorer.restoreFrom(child);

    auto root = restorer.obtainRoot();

    ASSERT_EQ(root, grand);

    ASSERT_EQ(grand->get(parentSide), parent);
    ASSERT_EQ(grand, parent->getParent());

    ASSERT_EQ(grand->get(!parentSide), uncle);
    ASSERT_EQ(grand, uncle->getParent());

    ASSERT_EQ(parent->getRight(), child);
    ASSERT_EQ(parent, child->getParent());

    ASSERT_TRUE(parent->isBlack());
    ASSERT_TRUE(uncle->isBlack());
    ASSERT_TRUE(grand->isRed());
    ASSERT_TRUE(child->isRed());

}