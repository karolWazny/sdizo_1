//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "Node.h"
#include "KeyFinder.h"
#include "NodePutter.h"
#include "ConsequentFinder.h"
#include "ConsequentLiberator.h"
#include "NodeReplacer.h"

template <typename T, typename U>
class RedBlackTree
{
public:
    RedBlackTree();
    void put(T key, U value);
    bool containsKey(T key);
    bool containsValue(U value);
    void removeKey(T key);
private:
    NodePointer<T, U> root;
};

template <typename T, typename U>
RedBlackTree<T, U>::RedBlackTree() {
    root = NodeFactory<T, U>::makeSentinel();
}

template<typename T, typename U>
void RedBlackTree<T, U>::put(T key, U value) {
    auto putter = NodePutter<T, U>(root);
    putter.put(key, value);
    root = putter.obtainRoot();
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

template<typename T, typename U>
void RedBlackTree<T, U>::removeKey(T key) {
    auto finder = KeyFinder<T, U>(root);
    finder.setDesiredKey(key);
    finder.find();
    bool treeContainsThatKey = finder.nodeFound();
    if(treeContainsThatKey)
    {
        auto nodeToRemove = finder.getFound();
        auto consequentFinder = ConsequentFinder<T, U>(nodeToRemove);
        auto consequent = consequentFinder.find();
        auto liberator = ConsequentLiberator<T, U>(consequent);
        liberator.free();
        root = liberator.obtainRoot();
        auto replacer = NodeReplacer<T, U>(nodeToRemove);
        replacer.replaceWithNode(consequent);
        root = replacer.obtainRoot();
    }
}

#endif //SDIZO_1_REDBLACKTREE_H
