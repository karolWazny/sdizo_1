//
// Created by admin on 13.03.2021.
//

#ifndef SDIZO_1_BINARYTREE_H
#define SDIZO_1_BINARYTREE_H

template <typename T>
using Node = RedBlackNodeImpl<T>;

template <typename T>
class RedBlackTree
{
public:
    RedBlackTree();
    void insert(T);
    int getSize();
    bool contains(T key);
    void remove(T key);
private:
    NodePointer<T> standardBinaryTreeInsert(T key);
    void restoreRedBlackPropertyStartingFrom(NodePointer<T> initialNode);
    void standardBinaryTreeRemove(T key);
    NodePointer<T> sentinel;
    int numberOfElements;
};

template<typename T>
RedBlackTree<T>::RedBlackTree() {
    sentinel = NodePointer<T>(new RedBlackSentinel<T>());
    numberOfElements = 0;
}

template<typename T>
void RedBlackTree<T>::insert(T key) {
    auto z = standardBinaryTreeInsert(key);
    restoreRedBlackPropertyStartingFrom(z);
    numberOfElements++;
}

template<typename T>
int RedBlackTree<T>::getSize() {
    return numberOfElements;
}

template<typename T>
NodePointer<T> RedBlackTree<T>::standardBinaryTreeInsert(T key) {
    NodePointer<T> addedNode(new NodeImpl<T>(sentinel, key));
    sentinel->insertAfter(addedNode);
    return addedNode;
}

template<typename T>
bool RedBlackTree<T>::contains(T key) {
    return sentinel->subtreeContains(key);
}

template<typename T>
void RedBlackTree<T>::restoreRedBlackPropertyStartingFrom(NodePointer<T> initialNode) {
    RedBlackPropertyRestorer<T> restorer = RedBlackPropertyRestorer<T>(initialNode);
    restorer.restore();
}

template<typename T>
void RedBlackTree<T>::remove(T key) {
    standardBinaryTreeRemove(key);
    numberOfElements--;
}

template<typename T>
void RedBlackTree<T>::standardBinaryTreeRemove(T key) {

}

#endif //SDIZO_1_BINARYTREE_H
