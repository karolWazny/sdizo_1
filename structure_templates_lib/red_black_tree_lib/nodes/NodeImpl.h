#ifndef SDIZO_1_NODEIMPL_H
#define SDIZO_1_NODEIMPL_H

#include "Node.h"
#include "SimpleFactory.h"

template <typename T, typename U>
class NodeImpl : public Node<T, U>
{
public:
    NodeImpl(T key, U value);
    U& getContent() override;
    T getKey()override;
    void setParent(NodePointer<T, U>) override;
    NodePointer<T, U> getParent() override;
    void setLeft(NodePointer<T, U>) override;
    NodePointer<T, U> getLeft() override;
    void setRight(NodePointer<T, U>) override;
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
NodePointer<T, U> NodeImpl<T, U>::sentinel = SimpleFactory<T, U>::makeSentinel();

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
    return parent.lock();
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

template<typename T, typename U>
void NodeImpl<T, U>::setLeft(NodePointer<T, U> node) {
    if(node)
        this->left = node;
    else
        this->left = sentinel;
}

template<typename T, typename U>
void NodeImpl<T, U>::setRight(NodePointer<T, U> node) {
    if(node)
        this->right = node;
    else
        this->right = sentinel;
}

template<typename T, typename U>
void NodeImpl<T, U>::setParent(NodePointer<T, U> node) {
    if(node)
        this->parent = node;
    else
        this->parent = sentinel;
}

#endif //SDIZO_1_NODEIMPL_H
