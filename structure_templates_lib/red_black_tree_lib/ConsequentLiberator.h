#ifndef SDIZO_1_CONSEQUENTLIBERATOR_H
#define SDIZO_1_CONSEQUENTLIBERATOR_H

#include "Node.h"
#include "NodeUtility.h"
#include "Side.h"


template <typename T, typename U>
class ConsequentLiberator : public NodeUtility<T, U>
{
public:
    explicit ConsequentLiberator(NodePointer<T, U> consequent);
    void free();
    NodePointer<T, U> getFreed();
private:
    NodePointer<T, U> nodeToFree;
};

template<typename T, typename U>
ConsequentLiberator<T, U>::ConsequentLiberator(NodePointer<T, U> consequent) {
    currentNode = nodeToFree = consequent;
}

template<typename T, typename U>
void ConsequentLiberator<T, U>::free(){
    auto child = nodeToFree->getRight();
    auto consequentSide = Side::LEFT;
    if(child->isNil())
    {
        child = nodeToFree->getLeft();
        consequentSide = Side::RIGHT;
    }
    auto parent = nodeToFree->getParent();
    child->setParent(parent);
    if(consequentSide == Side::LEFT)
    {
        parent->setLeft(child);
    }
    else
    {
        parent->setRight(child);
    }

    currentNode = child;
}

#endif //SDIZO_1_CONSEQUENTLIBERATOR_H
