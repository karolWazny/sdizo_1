//
// Created by admin on 15.03.2021.
//

#ifndef SDIZO_1_REDBLACKPOSTDELETEFIXER_H
#define SDIZO_1_REDBLACKPOSTDELETEFIXER_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackPostDeleteFixer
{
public:
    explicit RedBlackPostDeleteFixer(NodePointer<T> nodeX);
    RedBlackPostDeleteFixer() = delete;
    void fix();
private:
    NodePointer<T> nodeBeingProcessed;
};

template<typename T>
RedBlackPostDeleteFixer<T>::RedBlackPostDeleteFixer(NodePointer<T> nodeX) {
    nodeBeingProcessed = nodeX;
}

template<typename T>
void RedBlackPostDeleteFixer<T>::fix() {
    if(!nodeBeingProcessed->isRed())
        nodeBeingProcessed = nodeBeingProcessed->getParent();
    nodeBeingProcessed->paintBlack();
}

#endif //SDIZO_1_REDBLACKPOSTDELETEFIXER_H
