//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODE_H
#define SDIZO_1_REDBLACKNODE_H

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = std::shared_ptr<RedBlackNode<T>>;

template <typename T>
using NodeWeakPtr = std::weak_ptr<RedBlackNode<T>>;

template <typename T>
class RedBlackNode {
public:
    virtual void setParent(NodePointer <T> parent) = 0;
    virtual NodePointer<T> getParent() = 0;
    virtual NodePointer<T> getSibling() = 0;
    virtual NodePointer<T> getRightChild() = 0;
    virtual NodePointer<T> getLeftChild() = 0;
    virtual void insertAfter(NodePointer <T> newNode) = 0;
    virtual bool subtreeContains(T key) = 0;
    virtual bool isRed() = 0;
    virtual void paintBlack() = 0;
    virtual void paintRed() = 0;
    virtual void restoreRedBlackProperty() = 0;
    virtual T getKey() = 0;
};

#endif //SDIZO_1_REDBLACKNODE_H
