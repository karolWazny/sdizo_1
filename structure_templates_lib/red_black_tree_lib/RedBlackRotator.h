//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKROTATOR_H
#define SDIZO_1_REDBLACKROTATOR_H

#include "UsefulEnums.h"

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = std::shared_ptr<RedBlackNode<T>>;

template<typename T>
class RedBlackRotator
{
public:
    explicit RedBlackRotator(NodePointer<T> nodeToRotate);
    RedBlackRotator() = delete;
    void rotateRight();
    void rotateLeft();
private:
    Side rotationDirection;
    bool nodeBeingRotatedIsRightChild();
    void moveNodesChildUp();
    void rotate();
    void obtainProperChild();
    void moveNodeBeingRotatedDown();
    void transferSubtreeBetweenNodes();
    NodePointer<T> nodeToRotate;
    NodePointer<T> nodesParent;
    NodePointer<T> nodesChild;
};

template<typename T>
RedBlackRotator<T>::RedBlackRotator(NodePointer<T> nodeToRotate)
{
    this->nodeToRotate = nodeToRotate;
    nodesParent = nodeToRotate->getParent();
}

template<typename T>
void RedBlackRotator<T>::rotateRight()
{
    rotationDirection = Side::RIGHT;
    rotate();
}

template<typename T>
void RedBlackRotator<T>::rotateLeft()
{
    rotationDirection = Side::LEFT;
    rotate();
}

template<typename T>
bool RedBlackRotator<T>::nodeBeingRotatedIsRightChild() {
    return nodeToRotate->isRightChild();
}

template<typename T>
void RedBlackRotator<T>::moveNodesChildUp() {
    if(nodeBeingRotatedIsRightChild())
    {
        nodesParent->setRightChild(nodesChild);
    } else
    {
        nodesParent->setLeftChild(nodesChild);
    }
    nodesChild->setParent(nodesParent);
}

template<typename T>
void RedBlackRotator<T>::rotate() {
    obtainProperChild();
    moveNodesChildUp();
    transferSubtreeBetweenNodes();
    moveNodeBeingRotatedDown();
}

template<typename T>
void RedBlackRotator<T>::obtainProperChild() {
    if(rotationDirection == Side::LEFT)
    {
        nodesChild = nodeToRotate->getRightChild();
    }
    else
    {
        nodesChild = nodeToRotate->getLeftChild();
    }
}

template<typename T>
void RedBlackRotator<T>::moveNodeBeingRotatedDown() {
    if(rotationDirection == Side::LEFT)
    {
        nodesChild->setLeftChild(nodeToRotate);
    }
    else
    {
        nodesChild->setRightChild(nodeToRotate);
    }
    nodeToRotate->setParent(nodesChild);
}

template<typename T>
void RedBlackRotator<T>::transferSubtreeBetweenNodes() {
    //todo ładniejsza refaktoryzacja (może zwracać liść NIL zamiast nullptr z Node)
    if(rotationDirection == Side::LEFT)
    {
        nodeToRotate->setRightChild(nodesChild->getLeftChild());
        if(nodeToRotate->getRightChild())
        {
            nodeToRotate->getRightChild()->setParent(nodeToRotate);
        }
    }
    else
    {
        nodeToRotate->setLeftChild(nodesChild->getRightChild());
        if(nodeToRotate->getLeftChild())
        {
            nodeToRotate->getLeftChild()->setParent(nodeToRotate);
        }
    }
}

#endif //SDIZO_1_REDBLACKROTATOR_H
