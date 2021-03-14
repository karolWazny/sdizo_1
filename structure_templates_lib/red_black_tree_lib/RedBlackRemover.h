//
// Created by admin on 13.03.2021.
//

#ifndef SDIZO_1_REDBLACKREMOVER_H
#define SDIZO_1_REDBLACKREMOVER_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackRemover
{
public:
    explicit RedBlackRemover(NodePointer<T> nodeToRemove);
    RedBlackRemover() = delete;
    void remove();
private:
    NodePointer<T> obtainSubsequent();
    NodePointer<T> obtainSubsequentChild();
    void freeSubsequent();
    void replaceZWithSubsequent();

    NodePointer<T> nodeToRemove;
    NodePointer<T> subsequentOfNodeToRemove;
    NodePointer<T> subsequentChild;
};

template <typename T>
class SubsequentFinder
{
public:
    explicit SubsequentFinder(NodePointer<T> nodeZ);
    SubsequentFinder() = delete;
    NodePointer<T> find();
private:
    NodePointer<T> nodeZ;
    Side subsequentSide;
};

template<typename T>
SubsequentFinder<T>::SubsequentFinder(NodePointer<T> nodeZ) {
    this->nodeZ = nodeZ;
}

template<typename T>
NodePointer<T> SubsequentFinder<T>::find() {
    NodePointer<T> output = NodePointer<T>(nullptr);
    if(nodeZ->hasLeftChild())
    {
        output = nodeZ->getLeftChild();
        subsequentSide = Side::LEFT;
    }
    else if(nodeZ->hasRightChild())
    {
        output = nodeZ->getRightChild();
        subsequentSide = Side::RIGHT;
    }
    else
        return output;
    while(output->hasChildOnTheSide(!subsequentSide))
    {
        output = output->getChildOnTheSide(!subsequentSide);
    }
    return output;
}

template<typename T>
RedBlackRemover<T>::RedBlackRemover(NodePointer<T> nodeToRemove) {
    this->nodeToRemove = nodeToRemove;
    this->subsequentOfNodeToRemove = obtainSubsequent();
    this->subsequentChild = obtainSubsequentChild();
}

template<typename T>
void RedBlackRemover<T>::remove() {
    freeSubsequent();
    replaceZWithSubsequent();
}

template<typename T>
NodePointer<T> RedBlackRemover<T>::obtainSubsequent() {
    SubsequentFinder<T> finder = SubsequentFinder<T>(nodeToRemove);
    return finder.find();
}

template<typename T>
NodePointer<T> RedBlackRemover<T>::obtainSubsequentChild() {
    if(!subsequentOfNodeToRemove)
        return nullptr;
    if(subsequentOfNodeToRemove->isRightChild())
        return subsequentOfNodeToRemove->getLeftChild();
    else
        return subsequentOfNodeToRemove->getRightChild();
}

template<typename T>
void RedBlackRemover<T>::freeSubsequent() {
    if(!subsequentOfNodeToRemove)
        return;
    if(subsequentOfNodeToRemove->isRightChild())
        subsequentOfNodeToRemove->getParent()->setRightChild(subsequentChild);
    else
        subsequentOfNodeToRemove->getParent()->setLeftChild(subsequentChild);
    if(subsequentChild)
        subsequentChild->setParent(subsequentOfNodeToRemove->getParent());
}

template<typename T>
void RedBlackRemover<T>::replaceZWithSubsequent() {
    auto parent = nodeToRemove->getParent();
    if(nodeToRemove->isRightChild())
        parent->setRightChild(subsequentOfNodeToRemove);
    else
        parent->setLeftChild(subsequentOfNodeToRemove);
    if(!subsequentOfNodeToRemove)
        return;
    subsequentOfNodeToRemove->setLeftChild(nodeToRemove->getLeftChild());
    subsequentOfNodeToRemove->setRightChild(nodeToRemove->getRightChild());
}

#endif //SDIZO_1_REDBLACKREMOVER_H
