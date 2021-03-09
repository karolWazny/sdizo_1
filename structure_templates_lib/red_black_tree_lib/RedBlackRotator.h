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
    Side nodeBeingRotatedSide();
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
bool RedBlackRotator<T>::nodeBeingRotatedIsRightChild()
{
    return nodeToRotate->isRightChild();
}

template<typename T>
void RedBlackRotator<T>::moveNodesChildUp()
{
    nodesParent->setChildOnTheSide(nodesChild, nodeBeingRotatedSide());
    nodesChild->setParent(nodesParent);
}

template<typename T>
void RedBlackRotator<T>::rotate()
{
    obtainProperChild();
    moveNodesChildUp();
    transferSubtreeBetweenNodes();
    moveNodeBeingRotatedDown();
}

template<typename T>
void RedBlackRotator<T>::obtainProperChild()
{
    nodesChild = nodeToRotate->getChildOnTheSide(!rotationDirection);
}

template<typename T>
void RedBlackRotator<T>::moveNodeBeingRotatedDown()
{
    nodesChild->setChildOnTheSide(nodeToRotate, rotationDirection);
    nodeToRotate->setParent(nodesChild);
}

template<typename T>
void RedBlackRotator<T>::transferSubtreeBetweenNodes()
{
    nodeToRotate->setChildOnTheSide(nodesChild->getChildOnTheSide(rotationDirection), !rotationDirection);
    nodeToRotate->getChildOnTheSide(!rotationDirection)->setParent(nodeToRotate);
}

template<typename T>
Side RedBlackRotator<T>::nodeBeingRotatedSide() {
    return (nodeBeingRotatedIsRightChild() ? Side::RIGHT : Side::LEFT);
}

#endif //SDIZO_1_REDBLACKROTATOR_H
