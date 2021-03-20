//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_NODEIMPL_H
#define SDIZO_1_NODEIMPL_H

#include "Node.h"
#include "Sentinel.h"

template <typename T, typename U>
class NodeImpl : public Node<T, U>
{
public:
    NodeImpl(T key, U value);
    U& getContent() override;
    T getKey()override;
    NodePointer<T, U> getParent() override;
    NodePointer<T, U> getLeft() override;
    NodePointer<T, U> getRight() override;
    bool isNil() override;
private:
    T key;
    U value;
    NodePointer<T, U> right;
    NodePointer<T, U> left;
    NodeWeakPtr<T, U> parent;
    static NodePointer<T, U> sentinel;
};

template <typename T, typename U>
NodePointer<T, U> NodeImpl<T, U>::sentinel = NodePointer<T, U>(new Sentinel<T, U>());

template<typename T, typename U>
U& NodeImpl<T, U>::getContent() {
    return value;
}

template<typename T, typename U>
NodeImpl<T, U>::NodeImpl(T key, U value) {
    this->key = key;
    this->value = value;
    right = sentinel;
    left = sentinel;
    parent = sentinel;
}

template<typename T, typename U>
T NodeImpl<T, U>::getKey() {
    return key;
}

template<typename T, typename U>
NodePointer<T, U> NodeImpl<T, U>::getParent() {
    return parent;
}

template<typename T, typename U>
NodePointer<T, U> NodeImpl<T, U>::getLeft() {
    return left;
}

template<typename T, typename U>
NodePointer<T, U> NodeImpl<T, U>::getRight() {
    return right;
}

template<typename T, typename U>
bool NodeImpl<T, U>::isNil() {
    return false;
}

#endif //SDIZO_1_NODEIMPL_H
