#ifndef SDIZO_1_RBNODE_H
#define SDIZO_1_RBNODE_H

#include "Colored.h"
#include "Node.h"

template <typename T, typename U>
class RBNode : public Colored, public Node<T, U>
{
public:
    RBNode(Node<T, U>*, Colored*);

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
    std::unique_ptr<Node<T, U>> node;
    std::unique_ptr<Colored> colored;
};

template<typename T, typename U>
RBNode<T, U>::RBNode(Node<T, U> * nodeImpl, Colored * coloredImpl) {
    node = std::unique_ptr<Node<T, U>>(nodeImpl);
    colored = std::unique_ptr<Colored>(coloredImpl);
}

template<typename T, typename U>
bool RBNode<T, U>::isBlack() {
    return colored->isBlack();
}

template<typename T, typename U>
bool RBNode<T, U>::isRed() {
    return colored->isRed();
}

template<typename T, typename U>
void RBNode<T, U>::paintBlack() {
    colored->paintBlack();
}

template<typename T, typename U>
void RBNode<T, U>::paintRed() {
    colored->paintRed();
}

template<typename T, typename U>
U &RBNode<T, U>::getContent() {
    return node->getContent();
}

template<typename T, typename U>
T RBNode<T, U>::getKey() {
    return node->getKey();
}

template<typename T, typename U>
void RBNode<T, U>::setParent(NodePointer<T, U> parent) {
    node->setParent(parent);
}

template<typename T, typename U>
NodePointer<T, U> RBNode<T, U>::getParent() {
    return node->getParent();
}

template<typename T, typename U>
void RBNode<T, U>::setLeft(NodePointer<T, U> left) {
    node->setLeft(left);
}

template<typename T, typename U>
NodePointer<T, U> RBNode<T, U>::getLeft() {
    return node->getLeft();
}

template<typename T, typename U>
void RBNode<T, U>::setRight(NodePointer<T, U> right) {
    node->setRight(right);
}

template<typename T, typename U>
NodePointer<T, U> RBNode<T, U>::getRight() {
    return node->getRight();
}

template<typename T, typename U>
bool RBNode<T, U>::isNil() {
    return node->isNil();
}

#endif //SDIZO_1_RBNODE_H
