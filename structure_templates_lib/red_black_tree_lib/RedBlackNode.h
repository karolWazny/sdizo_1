//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODE_H
#define SDIZO_1_REDBLACKNODE_H

#include "RedBlackRotator.h"
#include "UsefulEnums.h"

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = RedBlackNode<T>*;

template <typename T>
using NodeWeakPtr = RedBlackNode<T>*;

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
    virtual NodePointer<T> getNodeWithKey(T key);
    void rotateParent();
    bool uncleIsRed();
    bool isChild();
    NodePointer<T> getChildOnTheSide(Side side);
    void setChildOnTheSide(NodePointer<T> child, Side side);
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

template<typename T>
NodePointer<T> RedBlackNode<T>::getChildOnTheSide(Side side) {
    switch(side)
    {
        case Side::LEFT:
            return getLeftChild();
            break;
        case Side::RIGHT:
            return getRightChild();
            break;
        default:
            throw "unrecognized side";
    }
}

template<typename T>
void RedBlackNode<T>::setChildOnTheSide(NodePointer<T> child, Side side) {
    switch(side)
    {
        case Side::LEFT:
            setLeftChild(child);
            return;
        case Side::RIGHT:
            setRightChild(child);
            return;
        default:
            throw "unrecognized side";
    }
}

template<typename T>
NodePointer<T> RedBlackNode<T>::getNodeWithKey(T key) {
    if(key < getKey())
    {
        if(key == getLeftChild()->getKey())
        {
            return getLeftChild();
        }
        else
        {
            return getLeftChild()->getNodeWithKey(key);
        }
    }
    else
    {
        if(key == getRightChild()->getKey())
        {
            return getRightChild();
        }
        else
        {
            return getRightChild()->getNodeWithKey(key);
        }
    }
}

#endif //SDIZO_1_REDBLACKNODE_H
