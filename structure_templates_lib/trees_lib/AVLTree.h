#ifndef SDIZO_1_AVLTREE_H
#define SDIZO_1_AVLTREE_H

#include "trees_lib/nodes/Node.h"
#include "trees_lib/node_util/KeyFinder.h"
#include "trees_lib/nodes/SimpleFactory.h"
#include "RBPutter.h"
#include "RBRemover.h"
#include "TreePrinter.h"

template <typename T>
class AVLTree {
public:
    AVLTree();
    void put(T key);
    bool containsKey(T key);
    void removeKey(T key);
    string toString();
    string getRepresentation();
    bool isEmpty();
private:
    NodePointer<T> root;
};

template<typename T>
AVLTree<T>::AVLTree() {
    root = SimpleFactory<T>::makeSentinel();
}

template<typename T>
void AVLTree<T>::put(T key) {
    auto putter = NodePutter<T>(root, new SimpleFactory<T>());
    putter.put(key);
    root = putter.obtainRoot();
}

template<typename T>
bool AVLTree<T>::containsKey(T key) {
    auto finder = KeyFinder<T>(root);
    finder.setDesiredKey(key);
    finder.find();
    return finder.nodeFound();
}

template<typename T>
void AVLTree<T>::removeKey(T key) {

}

template<typename T>
string AVLTree<T>::toString() {
    return TreePrinter<T>().toString(root);
}

template<typename T>
string AVLTree<T>::getRepresentation() {
    return TreePrinter<T>().rbMonospaceRepresentation(root);
}

template<typename T>
bool AVLTree<T>::isEmpty() {
    return root->isNil();
}

#endif //SDIZO_1_AVLTREE_H
