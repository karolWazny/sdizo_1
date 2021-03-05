//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODE_H
#define SDIZO_1_REDBLACKNODE_H
#ifdef SDIZO_1_REDBLACKTREE_H

#include <memory>

template <typename T>
class RedBlackNode;

template <typename T>
using NodePointer = std::shared_ptr<RedBlackNode<T>>;

template <typename T>
using NodeWeakPtr = std::weak_ptr<RedBlackNode<T>>;

template <typename T>
class RedBlackNode
{
public:
    RedBlackNode() = delete;
    RedBlackNode(NodePointer<T> parent, T key);
    void setParent(NodePointer<T> parent);
    void insertAfter(NodePointer<T> newNode);
    bool subtreeContains(T key);
    bool isRed();
private:
    T key;
    enum class Color : char
    {
        RED,
        BLACK
    };
    Color color;
    NodePointer<T> leftChild;
    NodePointer<T> rightChild;
    NodeWeakPtr<T> parent;
    void insertLeftwards(NodePointer<T> newNode);
    void insertRightwards(NodePointer<T> newNode);
    void insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child);
    bool leftSubtreeContains(T key);
    bool rightSubtreeContains(T key);
    bool subtreeOnTheSideOfContains(T key, NodePointer<T>& child);
};

template<typename T>
RedBlackNode<T>::RedBlackNode(NodePointer<T> parent, T key) {
    this->key= key;
    this->parent = parent;
    color = (parent? Color::RED : Color::BLACK);
    leftChild = NodePointer<T>(nullptr);
    rightChild = NodePointer<T>(nullptr);
}

template<typename T>
void RedBlackNode<T>::setParent(NodePointer<T> parent) {
    this->parent = parent;
}

template<typename T>
void RedBlackNode<T>::insertAfter(NodePointer<T> newNode) {
    if(newNode->key < this->key)
    {
        insertLeftwards(newNode);
        return;
    }
    insertRightwards(newNode);
    return;
}

template<typename T>
void RedBlackNode<T>::insertLeftwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, leftChild);
}

template<typename T>
void RedBlackNode<T>::insertRightwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, rightChild);
}

template<typename T>
void RedBlackNode<T>::insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child) {
    if(child == nullptr)
    {
        child = newNode;
        return;
    }
    newNode->setParent(child);
    child->insertAfter(newNode);
}

template<typename T>
bool RedBlackNode<T>::subtreeContains(T key) {
    if(this->key == key)
    {
        return true;
    }
    if(this->key > key)
    {
        return leftSubtreeContains(key);
    }
    return rightSubtreeContains(key);
}

template<typename T>
bool RedBlackNode<T>::leftSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, leftChild);
}

template<typename T>
bool RedBlackNode<T>::rightSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, rightChild);
}

template<typename T>
bool RedBlackNode<T>::subtreeOnTheSideOfContains(T key, NodePointer<T>& child) {
    if(child == nullptr)
    {
        return false;
    }
    return child->subtreeContains(key);
}

template<typename T>
bool RedBlackNode<T>::isRed() {
    return color == Color::RED;
}

#endif //SDIZO_1_REDBLACKTREE_H
#endif //SDIZO_1_REDBLACKNODE_H
