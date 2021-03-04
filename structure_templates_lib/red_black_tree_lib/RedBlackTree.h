//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackTree
{
public:
    RedBlackTree();
private:
    NodePointer<T> root;
};

template<typename T>
RedBlackTree<T>::RedBlackTree() {
    root = std::make_shared<RedBlackNode<T>>();
}

#endif //SDIZO_1_REDBLACKTREE_H
