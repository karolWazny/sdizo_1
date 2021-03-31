#ifndef SDIZO_1_RBNODE_H
#define SDIZO_1_RBNODE_H

#include "red_black_tree_lib/colors/Colored.h"
#include "Node.h"

template <typename T, typename U>
class RBNode;

template <typename T, typename U>
using RBNodePtr = std::shared_ptr<RBNode<T, U>>;

template <typename T, typename U>
class RBNode : public Colored, public Node<T, U>
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

    virtual bool isBlack() = 0;
    virtual bool isRed() = 0;
    virtual void paintBlack() = 0;
    virtual void paintRed() = 0;
};

template <typename T, typename U>
RBNodePtr<T, U> rbcast(NodePointer<T, U> node) {
    return std::dynamic_pointer_cast<RBNode<int, int>>(node);
}

#endif //SDIZO_1_RBNODE_H
