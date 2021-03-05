//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "RedBlackNode.h"

template <typename T>
using Node = RedBlackNode<T>;

template <typename T>
class RedBlackTree
{
public:
    RedBlackTree();
    void insert(T);
    int getSize();
    bool contains(T key);
private:
    NodePointer<T> standardBinaryTreeInsert(T key);
    NodePointer<T> root;
    int numberOfElements;
};

template<typename T>
RedBlackTree<T>::RedBlackTree() {
    root = NodePointer<T>(nullptr);
    numberOfElements = 0;
}

template<typename T>
void RedBlackTree<T>::insert(T key) {
    standardBinaryTreeInsert(key);
    numberOfElements++;
}

template<typename T>
int RedBlackTree<T>::getSize() {
    return numberOfElements;
}

template<typename T>
NodePointer<T> RedBlackTree<T>::standardBinaryTreeInsert(T key) {
    if(numberOfElements == 0)
    {
        root = NodePointer<T>(new Node<T>(nullptr, key));
        return root;
    }
    NodePointer<T> addedNode(new Node<T>(root, key));
    root->insertAfter(addedNode);
    return addedNode;
}

template<typename T>
bool RedBlackTree<T>::contains(T key) {
    return root->subtreeContains(key);
}

#endif //SDIZO_1_REDBLACKTREE_H
