#ifndef SDIZO_1_AVLNODEIMPL_H
#define SDIZO_1_AVLNODEIMPL_H

#include "trees_lib/nodes/AVLNode.h"

template <typename T>
class AVLNodeImpl : public AVLNode<T>
{
public:
    AVLNodeImpl(Node<T>*);
    AVLNode() = delete;

    T getKey()override;
    void setParent(NodePointer<T>) override;
    NodePointer<T> getParent() override;
    void setLeft(NodePointer<T>) override;
    NodePointer<T> getLeft() override;
    void setRight(NodePointer<T>) override;
    NodePointer<T> getRight() override;
    bool isNil() override;
    std::string toString() override;

private:
    std::unique_ptr<Node<T>> node;
    char balanceFactor;
};

template<typename T>
AVLNodeImpl<T>::AVLNodeImpl(Node <T> *nodeImpl) {
    node = std::unique_ptr<Node<T>>(nodeImpl);
    balanceFactor = 0;
}

template<typename T>
T AVLNodeImpl<T>::getKey() {
    return node->getKey();
}

template<typename T>
void AVLNodeImpl<T>::setParent(NodePointer <T> parent) {
    node->setParent(parent);
}

template<typename T>
NodePointer <T> AVLNodeImpl<T>::getParent() {
    return node->getParent();
}

template<typename T>
void AVLNodeImpl<T>::setLeft(NodePointer <T> left) {
    node->setLeft();
}

template<typename T>
NodePointer <T> AVLNodeImpl<T>::getLeft() {
    return node->getLeft();
}

template<typename T>
void AVLNodeImpl<T>::setRight(NodePointer <T> right) {
    node->setRight(right);
}

template<typename T>
NodePointer <T> AVLNodeImpl<T>::getRight() {
    return node->getRight();
}

template<typename T>
bool AVLNodeImpl<T>::isNil() {
    return node->isNil();
}

template<typename T>
std::string AVLNodeImpl<T>::toString() {
    std::string out;
    switch(balanceFactor)
    {
        case -1:
            out += "-";
            break;
        case 0:
            out += "*";
            break;
        case 1:
            out += "+";
            break;
    }
    out += "|";
    out += node->toString();
    return out;
}

#endif //SDIZO_1_AVLNODEIMPL_H
