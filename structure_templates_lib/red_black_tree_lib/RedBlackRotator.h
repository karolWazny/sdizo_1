//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKROTATOR_H
#define SDIZO_1_REDBLACKROTATOR_H

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
    if(!nodesParent)
    {
        return;
    }
    nodesChild = nodeToRotate->getLeftChild();
    bool nodeBeingRotatedIsRightChild = nodeToRotate->isRightChild();
    //wypłynięcie lewego syna w górę
    if(nodeBeingRotatedIsRightChild)
    {
        nodesParent->setRightChild(nodesChild);
    } else
    {
        nodesParent->setLeftChild(nodesChild);
    }
    nodesChild->setParent(nodesParent);
    //
    nodeToRotate->setLeftChild(nodesChild->getRightChild());
    if(nodeToRotate->getLeftChild())
    {
        nodeToRotate->getLeftChild()->setParent(nodeToRotate);
    }
    nodesChild->setRightChild(nodeToRotate);
    nodeToRotate->setParent(nodesChild);
}

template<typename T>
void RedBlackRotator<T>::rotateLeft()
{
    if(!nodesParent)
    {
        return;
    }
    nodesChild = nodeToRotate->getRightChild();
    bool nodeBeingRotatedIsRightChild = nodeToRotate->isRightChild();
    //wypłynięcie lewego syna w górę
    if(nodeBeingRotatedIsRightChild)
    {
        nodesParent->setRightChild(nodesChild);
    } else
    {
        nodesParent->setLeftChild(nodesChild);
    }
    nodesChild->setParent(nodesParent);
    //
    nodeToRotate->setRightChild(nodesChild->getLeftChild());
    if(nodeToRotate->getRightChild())
    {
        nodeToRotate->getRightChild()->setParent(nodeToRotate);
    }
    nodesChild->setLeftChild(nodeToRotate);
    nodeToRotate->setParent(nodesChild);
}

#endif //SDIZO_1_REDBLACKROTATOR_H
