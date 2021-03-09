//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKSENTINEL_H
#define SDIZO_1_REDBLACKSENTINEL_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackSentinel : public RedBlackNode<T>
{
public:
    RedBlackSentinel();
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
    NodePointer<T> root;
};

template<typename T>
void RedBlackSentinel<T>::setParent(std::shared_ptr <RedBlackNode<T>> parent) {
    //do nothing
}

template<typename T>
std::shared_ptr <RedBlackNode<T>> RedBlackSentinel<T>::getParent() {
    return nullptr;
}

template<typename T>
std::shared_ptr <RedBlackNode<T>> RedBlackSentinel<T>::getSibling() {
    return nullptr;
}

template<typename T>
std::shared_ptr <RedBlackNode<T>> RedBlackSentinel<T>::getRightChild() {
    return nullptr;
}

template<typename T>
std::shared_ptr <RedBlackNode<T>> RedBlackSentinel<T>::getLeftChild() {
    return nullptr;
}

template<typename T>
void RedBlackSentinel<T>::insertAfter(std::shared_ptr <RedBlackNode<T>> newNode) {
    if(root == nullptr)
    {
        root = newNode;
        return;
    }
    newNode->setParent(root);
    root->insertAfter(newNode);
}

template<typename T>
bool RedBlackSentinel<T>::subtreeContains(T key) {
    return root->subtreeContains(key);
}

template<typename T>
bool RedBlackSentinel<T>::isRed() {
    return false;
}

template<typename T>
void RedBlackSentinel<T>::paintBlack() {
    //do nothing
}

template<typename T>
void RedBlackSentinel<T>::paintRed() {
    //do nothing
}

template<typename T>
T RedBlackSentinel<T>::getKey() {
    return NULL;
}

template<typename T>
RedBlackSentinel<T>::RedBlackSentinel() {
    root = NodePointer<T>(nullptr);
}

template<typename T>
bool RedBlackSentinel<T>::isRightChild() {
    return false;
}

template<typename T>
void RedBlackSentinel<T>::setRightChild(NodePointer<T> child) {
    root = child;
}

template<typename T>
void RedBlackSentinel<T>::setLeftChild(NodePointer<T> child) {
    root = child;
}

#endif //SDIZO_1_REDBLACKSENTINEL_H
