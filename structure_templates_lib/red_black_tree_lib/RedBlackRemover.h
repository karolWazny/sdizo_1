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

    NodePointer<T> nodeToRemove;
    NodePointer<T> subsequentOfNodeToRemove;
    NodePointer<T> subsequentChild;
};

template<typename T>
RedBlackRemover<T>::RedBlackRemover(NodePointer<T> nodeToRemove) {
    this->nodeToRemove = nodeToRemove;
    this->subsequentOfNodeToRemove = obtainSubsequent();
    this->subsequentChild = obtainSubsequentChild();
}

template<typename T>
void RedBlackRemover<T>::remove() {

}

template<typename T>
NodePointer<T> RedBlackRemover<T>::obtainSubsequent() {
    return nullptr;
}

template<typename T>
NodePointer<T> RedBlackRemover<T>::obtainSubsequentChild() {
    return nullptr;
}

#endif //SDIZO_1_REDBLACKREMOVER_H
