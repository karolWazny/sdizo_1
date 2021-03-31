#ifndef SDIZO_1_RBNODEIMPL_H
#define SDIZO_1_RBNODEIMPL_H

#include "RBNode.h"
#include "RBSentinel.h"

template <typename T, typename U>
class RBNodeImpl : public RBNode<T, U>
{
public:
    RBNodeImpl(Node<T, U>*, Colored*);

    bool isBlack() override;
    bool isRed() override;
    void paintBlack() override;
    void paintRed() override;

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
    RBNodePtr<T, U> sentinel();
    std::unique_ptr<Node<T, U>> node;
    std::unique_ptr<Colored> colored;

};

template<typename T, typename U>
RBNodePtr<T, U> RBNodeImpl<T, U>::sentinel() {
    return RBSentinel<T, U>::getInstance();
}

template<typename T, typename U>
RBNodeImpl<T, U>::RBNodeImpl(Node<T, U> * nodeImpl, Colored * coloredImpl) {
    node = std::unique_ptr<Node<T, U>>(nodeImpl);
    node->setRight(sentinel());
    node->setLeft(sentinel());
    node->setParent(sentinel());
    colored = std::unique_ptr<Colored>(coloredImpl);
    colored->paintRed();
}

template<typename T, typename U>
bool RBNodeImpl<T, U>::isBlack() {
    return colored->isBlack();
}

template<typename T, typename U>
bool RBNodeImpl<T, U>::isRed() {
    return colored->isRed();
}

template<typename T, typename U>
void RBNodeImpl<T, U>::paintBlack() {
    colored->paintBlack();
}

template<typename T, typename U>
void RBNodeImpl<T, U>::paintRed() {
    colored->paintRed();
}

template<typename T, typename U>
U &RBNodeImpl<T, U>::getContent() {
    return node->getContent();
}

template<typename T, typename U>
T RBNodeImpl<T, U>::getKey() {
    return node->getKey();
}

template<typename T, typename U>
void RBNodeImpl<T, U>::setParent(NodePointer<T, U> parent) {
    if(!parent)
        node->setParent(sentinel());
    else
    node->setParent(parent);
}

template<typename T, typename U>
NodePointer<T, U> RBNodeImpl<T, U>::getParent() {
    return node->getParent();
}

template<typename T, typename U>
void RBNodeImpl<T, U>::setLeft(NodePointer<T, U> left) {
    if(!left)
        node->setLeft(sentinel());
    else
    node->setLeft(left);
}

template<typename T, typename U>
NodePointer<T, U> RBNodeImpl<T, U>::getLeft() {
    return node->getLeft();
}

template<typename T, typename U>
void RBNodeImpl<T, U>::setRight(NodePointer<T, U> right) {
    if(!right)
        node->setRight(sentinel());
    else
    node->setRight(right);
}

template<typename T, typename U>
NodePointer<T, U> RBNodeImpl<T, U>::getRight() {
    return node->getRight();
}

template<typename T, typename U>
bool RBNodeImpl<T, U>::isNil() {
    return node->isNil();
}

#endif //SDIZO_1_RBNODEIMPL_H
