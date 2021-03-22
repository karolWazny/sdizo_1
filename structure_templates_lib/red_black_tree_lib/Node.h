//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_NODE_H
#define SDIZO_1_NODE_H

#include <memory>

template <typename T, typename U>
class Node;

template <typename T, typename U>
using NodePointer = std::shared_ptr<Node<T, U>>;

template <typename T, typename U>
using NodeWeakPtr = std::shared_ptr<Node<T, U>>;

template <typename T, typename U>
class Node
{
public:
    virtual U& getContent() = 0;
    virtual T getKey() = 0;
    virtual void setParent(NodePointer<T, U>) = 0;
    virtual NodePointer<T, U> getParent() = 0;
    virtual void setLeft(NodePointer<T, U>) = 0;
    virtual NodePointer<T, U> getLeft() = 0;
    virtual void setRight(NodePointer<T, U>) = 0;
    virtual NodePointer<T, U> getRight() = 0;
    virtual bool isNil() = 0;
};

#endif //SDIZO_1_NODE_H
