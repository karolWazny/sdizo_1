#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/KeyFinder.h"
#include "red_black_tree_lib/nodes/RBFactory.h"
#include "RBPutter.h"
#include "RBRemover.h"
#include "TreePrinter.h"


template <typename T, typename U>
class RedBlackTree
{
public:
    RedBlackTree();
    void put(T key, U value);
    bool containsKey(T key);
    bool containsValue(U value);
    void removeKey(T key);
    string toString();
private:
    NodePointer<T, U> root;
};

template <typename T, typename U>
RedBlackTree<T, U>::RedBlackTree() {
    root = SimpleFactory<T, U>::makeSentinel();
}

template<typename T, typename U>
void RedBlackTree<T, U>::put(T key, U value) {
    auto putter = RBPutter<T, U>(root);
    putter.put(key, value);
    root = putter.obtainRoot();
    rbcast(root)->checkAmountOfBlackToLeaves();
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
    auto remover = RBRemover<T, U>(root);
    remover.remove(key);
    root = remover.obtainRoot();
    rbcast(root)->checkAmountOfBlackToLeaves();
}

template<typename T, typename U>
string RedBlackTree<T, U>::toString() {
    return TreePrinter<T, U>().toString(root);
}

#endif //SDIZO_1_REDBLACKTREE_H
