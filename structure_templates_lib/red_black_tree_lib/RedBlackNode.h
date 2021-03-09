//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODE_H
#define SDIZO_1_REDBLACKNODE_H

#include "RedBlackRotator.h"

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = std::shared_ptr<RedBlackNode<T>>;

template <typename T>
using NodeWeakPtr = std::weak_ptr<RedBlackNode<T>>;

template <typename T>
class RedBlackNode {
public:
    virtual void setParent(NodePointer <T> parent) = 0;
    virtual NodePointer<T> getParent() = 0;
    virtual NodePointer<T> getSibling() = 0;
    virtual NodePointer<T> getRightChild() = 0;
    virtual NodePointer<T> getLeftChild() = 0;
    virtual void insertAfter(NodePointer <T> newNode) = 0;
    virtual bool subtreeContains(T key) = 0;
    virtual bool isRed() = 0;
    virtual void paintBlack() = 0;
    virtual void paintRed() = 0;
    virtual T getKey() = 0;
    virtual bool isRightChild() = 0;
    virtual void setRightChild(NodePointer<T>) = 0;
    virtual void setLeftChild(NodePointer<T>) = 0;
    void rotateParent();
    bool uncleIsRed();
    bool isChild();
private:
    NodePointer<T> getUncle();
};

template<typename T>
bool RedBlackNode<T>::uncleIsRed() {
    auto uncle = getUncle();
    if (!uncle) {
        return false;
    }
    return uncle->isRed();
}

template<typename T>
NodePointer<T> RedBlackNode<T>::getUncle() {
    if(!isChild())
    {
        return NodePointer<T>(nullptr);
    }
    return getParent()->getSibling();
}

template<typename T>
bool RedBlackNode<T>::isChild() {
    return getParent() != nullptr;
}

template<typename T>
void RedBlackNode<T>::rotateParent()
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

#endif //SDIZO_1_REDBLACKNODE_H
