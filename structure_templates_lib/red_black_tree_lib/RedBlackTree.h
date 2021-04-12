#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/KeyFinder.h"
#include "red_black_tree_lib/nodes/RBFactory.h"
#include "RBPutter.h"
#include "RBRemover.h"
#include "TreePrinter.h"


template <typename T>
class RedBlackTree
{
public:
    RedBlackTree();
    void put(T key);
    bool containsKey(T key);
    void removeKey(T key);
    string toString();
    string getRepresentation();
private:
    NodePointer<T> root;
};

template <typename T>
RedBlackTree<T>::RedBlackTree() {
    root = SimpleFactory<T>::makeSentinel();
}

template<typename T>
void RedBlackTree<T>::put(T key) {
    auto putter = RBPutter<T>(root);
    putter.put(key);
    root = putter.obtainRoot();
    rbcast(root)->checkAmountOfBlackToLeaves();
}

template<typename T>
bool RedBlackTree<T>::containsKey(T key) {
    auto finder = KeyFinder<T>(root);
    finder.setDesiredKey(key);
    finder.find();
    return finder.nodeFound();
}

template<typename T>
void RedBlackTree<T>::removeKey(T key) {
    auto remover = RBRemover<T>(root);
    remover.remove(key);
    root = remover.obtainRoot();
    rbcast(root)->checkAmountOfBlackToLeaves();
}

template<typename T>
string RedBlackTree<T>::toString() {
    return TreePrinter<T>().toString(root);
}

template<typename T>
string RedBlackTree<T>::getRepresentation() {
    return TreePrinter<T>().rbMonospaceRepresentation(root);
}

#endif //SDIZO_1_REDBLACKTREE_H
