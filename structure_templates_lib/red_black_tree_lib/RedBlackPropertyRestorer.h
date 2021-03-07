//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKPROPERTYRESTORER_H
#define SDIZO_1_REDBLACKPROPERTYRESTORER_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackPropertyRestorer
{
public:
    RedBlackPropertyRestorer() = delete;
    RedBlackPropertyRestorer(NodePointer<T> nodeZ);
    void restore();
private:
    enum class Side : char
    {
        RIGHT,
        LEFT
    };
    NodePointer<T> nodeZ;
    NodePointer<T> zParent;
    Side parentSide;
    Side getChildSide(NodePointer<T> child);
};

template <typename T>
RedBlackPropertyRestorer<T>::RedBlackPropertyRestorer(NodePointer<T> nodeZ)
{
    this->nodeZ = nodeZ;
    zParent = this->nodeZ->getParent();
    parentSide = getChildSide(zParent);
}

template<typename T>
void RedBlackPropertyRestorer<T>::restore() {
    if(!(zParent->isRed()))
    {
        return;
    }
    if(zParent->getSibling() != nullptr && zParent->getSibling()->isRed())
    {
        zParent->paintBlack();
        zParent->getSibling()->paintBlack();
        zParent->getParent()->paintRed();
        auto restorer = RedBlackPropertyRestorer<T>(zParent->getParent());
        restorer.restore();
        return;
        //logikę z tego bloku wypindolić do NodeImpl
    }
    if(parentSide != getChildSide(nodeZ))
    {
        nodeZ->rotateParent();
        auto restorer = RedBlackPropertyRestorer<T>(zParent);
        restorer.restore();
        return;
    }
    zParent->paintBlack();
    zParent->getParent()->paintRed();
    zParent->rotateParent();
}

template<typename T>
typename RedBlackPropertyRestorer<T>::Side RedBlackPropertyRestorer<T>::getChildSide(NodePointer<T> child) {
    return (child->isRightChild() ? Side::RIGHT : Side::LEFT);
}

#endif //SDIZO_1_REDBLACKPROPERTYRESTORER_H
