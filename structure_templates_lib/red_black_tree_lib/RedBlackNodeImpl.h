//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODEIMPL_H
#define SDIZO_1_REDBLACKNODEIMPL_H
#ifdef SDIZO_1_REDBLACKTREE_H

#include <memory>
#include "RedBlackNode.h"

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
    void restoreRedBlackProperty() override;
    T getKey() override;
private:
    T key;
    enum class Color : char
    {
        RED,
        BLACK
    };
    Color color;
    NodePointer<T> leftChild;
    NodePointer<T> rightChild;
    NodeWeakPtr<T> parent;
    NodePointer<T> getRightChild() override;
    NodePointer<T> getLeftChild() override;
    RedBlackNodeImpl(NodePointer<T> parent, T key);
    void insertLeftwards(NodePointer<T> newNode);
    void insertRightwards(NodePointer<T> newNode);
    void insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child);
    bool leftSubtreeContains(T key);
    bool rightSubtreeContains(T key);
    bool subtreeOnTheSideOfContains(T key, NodePointer<T>& child);
    NodePointer<T> getParent();
    NodePointer<T> getSibling();
    NodePointer<T> getUncle();
    bool parentIsRed();
    bool uncleIsRed();
    bool isRightChild();
    bool isChild();
    void paintRed();
    void paintBlack();
    void rotateRight();
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
NodePointer<T> RedBlackNodeImpl<T>::getUncle() {
    if(!isChild())
    {
        return NodePointer<T>(nullptr);
    }
    return getParent()->getSibling();
}

template<typename T>
void RedBlackNodeImpl<T>::restoreRedBlackProperty() {
    if(!parentIsRed())
    {
        return;
    }
    if(uncleIsRed())
    {
        auto uncle = getUncle();
        uncle->paintBlack();
        getParent()->paintBlack();
        auto grandpa = uncle->getParent();
        grandpa->paintRed();
        grandpa->restoreRedBlackProperty();
        return;
    }
    /*if(!isRightChild())
    {
        getParent()->paintBlack();
        auto grandpa = getParent()->getParent();
        grandpa->paintRed();
        grandpa->rotateRight();
    }*/
}

template<typename T>
void RedBlackNodeImpl<T>::paintRed() {
    color = Color::RED;
}

template<typename T>
void RedBlackNodeImpl<T>::paintBlack() {
    color = Color::BLACK;
}

template<typename T>
bool RedBlackNodeImpl<T>::uncleIsRed() {
    auto uncle = getUncle();
    if (!uncle) {
        return false;
    }
    return uncle->isRed();
}

template<typename T>
bool RedBlackNodeImpl<T>::isRightChild() {
    if(!isChild())
    {
        return false;
    }
    auto parentKey = getParent()->key;
    return (this->key >= parentKey);
}

template<typename T>
bool RedBlackNodeImpl<T>::isChild() {
    return getParent() != nullptr;
}

template<typename T>
bool RedBlackNodeImpl<T>::parentIsRed() {
    if(isChild())
    {
        return getParent()->isRed();
    }
    return false;
}

template<typename T>
void RedBlackNodeImpl<T>::rotateRight() {
    auto bufferForLeftKid = leftChild;
    leftChild = leftChild->rightChild;

}

template<typename T>
T RedBlackNodeImpl<T>::getKey() {
    return key;
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getRightChild() {
    return rightChild;
}

template<typename T>
NodePointer<T> RedBlackNodeImpl<T>::getLeftChild() {
    return leftChild;
}

#endif //SDIZO_1_REDBLACKTREE_H
#endif //SDIZO_1_REDBLACKNODEIMPL_H
