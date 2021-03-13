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
    NodePointer<T> nodeToRemove;
};

template<typename T>
RedBlackRemover<T>::RedBlackRemover(NodePointer<T> nodeToRemove) {
    this->nodeToRemove = nodeToRemove;
}

template<typename T>
void RedBlackRemover<T>::remove() {

}

#endif //SDIZO_1_REDBLACKREMOVER_H
