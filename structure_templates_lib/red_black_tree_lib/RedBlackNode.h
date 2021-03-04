//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODE_H
#define SDIZO_1_REDBLACKNODE_H
#ifdef SDIZO_1_REDBLACKTREE_H

#include <memory>

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = std::shared_ptr<RedBlackNode<T>>;

template <typename T>
class RedBlackNode
{
private:
    NodePointer<T> leftChild;
    NodePointer<T> rightChild;
};

#endif //SDIZO_1_REDBLACKTREE_H
#endif //SDIZO_1_REDBLACKNODE_H
