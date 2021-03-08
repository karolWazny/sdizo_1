//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODEIMPL_H
#define SDIZO_1_REDBLACKNODEIMPL_H
#ifdef SDIZO_1_REDBLACKTREE_H

#include <memory>
#include "RedBlackNode.h"
#include "UsefulEnums.h"

template <typename T>
class RedBlackTree;

template <typename T>
class RedBlackNodeImpl : public RedBlackNode<T>
{
    friend RedBlackTree<T>;
public:
    RedBlackNodeImpl() = delete;
    void setParent(NodePointer<T> parent) override;
    void insertAfter(NodePointer<T> newNode) override;
    bool subtreeContains(T key) override;
    bool isRed() override;
    T getKey() override;
private:
    T key;
    Color color;
    NodePointer<T> leftChild;
    NodePointer<T> rightChild;
    NodeWeakPtr<T> parent;
    NodePointer<T> getRightChild() override;
    NodePointer<T> getLeftChild() override;
    void setRightChild(NodePointer<T> rightChild) override;
    void setLeftChild(NodePointer<T> leftChild) override;
    RedBlackNodeImpl(NodePointer<T> parent, T key);
    void insertLeftwards(NodePointer<T> newNode);
    void insertRightwards(NodePointer<T> newNode);
    void insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child);
    bool leftSubtreeContains(T key);
    bool rightSubtreeContains(T key);
    bool subtreeOnTheSideOfContains(T key, NodePointer<T>& child);
    NodePointer<T> getParent();
    NodePointer<T> getSibling();
    bool parentIsRed();
    bool isRightChild();
    void paintRed();
    void paintBlack();
    void rotateParent();
};

template<typename T>
RedBlackNodeImpl<T>::RedBlackNodeImpl(NodePointer<T> parent, T key) {
    this->key= key;
    this->parent = parent;
    color = (parent? Color::RED : Color::BLACK);
    leftChild = NodePointer<T>(nullptr);
    rightChild = NodePointer<T>(nullptr);
}

template<typename T>
void RedBlackNodeImpl<T>::setParent(NodePointer<T> parent) {
    this->parent = parent;
}

template<typename T>
void RedBlackNodeImpl<T>::insertAfter(NodePointer<T> newNode) {
    if(newNode->getKey() < this->key)
    {
        insertLeftwards(newNode);
        return;
    }
    insertRightwards(newNode);
    return;
}

template<typename T>
void RedBlackNodeImpl<T>::insertLeftwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, leftChild);
}

template<typename T>
void RedBlackNodeImpl<T>::insertRightwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, rightChild);
}

template<typename T>
void RedBlackNodeImpl<T>::insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child) {
    if(child == nullptr)
    {
        child = newNode;
        return;
    }
    newNode->setParent(child);
    child->insertAfter(newNode);
}

template<typename T>
bool RedBlackNodeImpl<T>::subtreeContains(T key) {
    if(this->key == key)
    {
        return true;
    }
    if(this->key > key)
    {
        return leftSubtreeContains(key);
    }
    return rightSubtreeContains(key);
}

template<typename T>
bool RedBlackNodeImpl<T>::leftSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, leftChild);
}

template<typename T>
bool RedBlackNodeImpl<T>::rightSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, rightChild);
}

template<typename T>
bool RedBlackNodeImpl<T>::subtreeOnTheSideOfContains(T key, NodePointer<T>& child) {
    if(child == nullptr)
    {
        return false;
    }
    return child->subtreeContains(key);
}

template<typename T>
bool RedBlackNodeImpl<T>::isRed() {
    return color == Color::RED;
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getParent() {
    return parent.lock();
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getSibling() {
    if(!isChild())
    {
        return NodePointer<T>(nullptr);
    }
    auto parentKey = getParent()->getKey();
    if(parentKey > this->key)
    {
        return getParent()->getRightChild();
    }
    return getParent()->getLeftChild();
}

template<typename T>
void RedBlackNodeImpl<T>::paintRed()
{
    color = Color::RED;
}

template<typename T>
void RedBlackNodeImpl<T>::paintBlack()
{
    color = Color::BLACK;
}

template<typename T>
bool RedBlackNodeImpl<T>::isRightChild()
{
    if(!isChild())
    {
        return false;
    }
    auto parentKey = getParent()->getKey();
    return (this->key >= parentKey);
}
template<typename T>
bool RedBlackNodeImpl<T>::parentIsRed()
{
    if(isChild())
    {
        return getParent()->isRed();
    }
    return false;
}

template<typename T>
T RedBlackNodeImpl<T>::getKey()
{
    return key;
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getRightChild()
{
    return rightChild;
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getLeftChild()
{
    return leftChild;
}

template<typename T>
void RedBlackNodeImpl<T>::setRightChild(NodePointer<T> rightChild)
{
    this->rightChild = rightChild;
}

template<typename T>
void RedBlackNodeImpl<T>::setLeftChild(NodePointer<T> leftChild)
{
    this->leftChild = leftChild;
}

template<typename T>
void RedBlackNodeImpl<T>::rotateParent()
{
    RedBlackRotator<T> rotator = RedBlackRotator<T>(getParent());
    if(isRightChild())
    {
        rotator.rotateLeft();
        return;
    }
    else
    {
      rotator.rotateRight();
      return;
    }
}


#endif //SDIZO_1_REDBLACKTREE_H
#endif //SDIZO_1_REDBLACKNODEIMPL_H
