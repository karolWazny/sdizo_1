//
// Created by admin on 09.03.2021.
//

#ifndef SDIZO_1_REDBLACKNIL_H
#define SDIZO_1_REDBLACKNIL_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackNil : public RedBlackNode<T>
{
    void setParent(NodePointer <T> parent);
    NodePointer<T> getParent();
    NodePointer<T> getSibling();
    NodePointer<T> getRightChild();
    NodePointer<T> getLeftChild();
    void insertAfter(NodePointer <T> newNode);
    bool subtreeContains(T key);
    bool isRed();
    void paintBlack();
    void paintRed();
    T getKey();
    bool isRightChild();
    void setRightChild(NodePointer<T>);
    void setLeftChild(NodePointer<T>);

private:
    NodePointer<T> parent;
};

template<typename T>
bool RedBlackNil<T>::subtreeContains(T key) {
    return false;
}

template<typename T>
void RedBlackNil<T>::insertAfter(NodePointer<T> newNode) {
    //do nothing
}

template<typename T>
bool RedBlackNil<T>::isRed() {
    return false;
}

template<typename T>
void RedBlackNil<T>::paintBlack() {
    //do nothing
}

template<typename T>
void RedBlackNil<T>::paintRed() {
    //do nothing
}

template<typename T>
NodePointer<T> RedBlackNil<T>::getRightChild() {
    throw "trying to get NIL's child!";
}

template<typename T>
NodePointer<T> RedBlackNil<T>::getLeftChild() {
    throw "trying to get NIL's child!";
}

template<typename T>
void RedBlackNil<T>::setParent(NodePointer<T> parent) {
    //do nothing;
    //this function exists ONLY to simplify rotating operations
    //on nodes having only one or none childs
}

template<typename T>
NodePointer<T> RedBlackNil<T>::getSibling() {
    return nullptr;
}

template<typename T>
NodePointer<T> RedBlackNil<T>::getParent() {
    return nullptr;
}

template<typename T>
T RedBlackNil<T>::getKey() {
    return NULL;
}

template<typename T>
bool RedBlackNil<T>::isRightChild() {
    return false;
}

template<typename T>
void RedBlackNil<T>::setRightChild(NodePointer<T>) {

}

template<typename T>
void RedBlackNil<T>::setLeftChild(NodePointer<T>) {

}

#endif //SDIZO_1_REDBLACKNIL_H
