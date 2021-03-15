//
// Created by admin on 04.03.2021.
//

#ifndef SDIZO_1_REDBLACKNODEIMPL_H
#define SDIZO_1_REDBLACKNODEIMPL_H
#ifdef SDIZO_1_REDBLACKTREE_H

#include <memory>
#include "RedBlackNode.h"
#include "UsefulEnums.h"
#include "RedBlackNil.h"
#include "NodeImpl.h"
#include "RedBlackRemover.h"

template <typename T>
class RedBlackTree;

template <typename T>
class RedBlackNodeImpl : public NodeImpl<T>
{
    friend RedBlackTree<T>;
public:
    RedBlackNodeImpl() = delete;
    bool isRed() override;
    void remove() override;
private:
    Color color;
    RedBlackNodeImpl(NodePointer<T> parent, T key);
    bool parentIsRed();
    void paintRed();
    void paintBlack();
};

template<typename T>
RedBlackNodeImpl<T>::RedBlackNodeImpl(NodePointer<T> parent, T key) : NodeImpl<T>(parent, key)
{
    color = (parent? Color::RED : Color::BLACK);
}

template<typename T>
bool RedBlackNodeImpl<T>::isRed() {
    return color == Color::RED;
}

template<typename T>
void RedBlackNodeImpl<T>::paintRed()
{
    color = Color::RED;
}

template<typename T>
void RedBlackNodeImpl<T>::paintBlack()
{
    color = Color::BLACK;
}

template<typename T>
bool RedBlackNodeImpl<T>::parentIsRed()
{
    if(isChild())
    {
        return getParent()->isRed();
    }
    return false;
}

template<typename T>
void RedBlackNodeImpl<T>::remove() {
    auto remover = RedBlackRemover<T>(this);
    remover.remove();
}

#endif //SDIZO_1_REDBLACKTREE_H
#endif //SDIZO_1_REDBLACKNODEIMPL_H
