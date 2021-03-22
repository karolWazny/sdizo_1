//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "Node.h"
#include "NodeImpl.h"
#include "KeyFinder.h"

template <typename T, typename U>
class RedBlackTree
{
public:
    RedBlackTree();
    void put(T key, U value);
    bool containsKey(T key);
    bool containsValue(U value);
private:
    NodePointer<T, U> root;
};

template <typename T, typename U>
RedBlackTree<T, U>::RedBlackTree() {
    root = NodePointer<T, U>(new Sentinel<T, U>());
}

template<typename T, typename U>
void RedBlackTree<T, U>::put(T key, U value) {
    root = NodePointer<T, U>(new NodeImpl<T, U>(key, value));
}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsKey(T key) {
    auto finder = KeyFinder<T, U>(root);
    finder.setDesiredKey(key);
    finder.find();
    return finder.nodeFound();
}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsValue(U value) {
    return true;
}

#endif //SDIZO_1_REDBLACKTREE_H
