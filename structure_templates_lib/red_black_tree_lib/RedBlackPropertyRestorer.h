//
// Created by admin on 06.03.2021.
//

#ifndef SDIZO_1_REDBLACKPROPERTYRESTORER_H
#define SDIZO_1_REDBLACKPROPERTYRESTORER_H

#include "RedBlackNode.h"
#include "UsefulEnums.h"

template <typename T>
class RedBlackPropertyRestorer
{
public:
    RedBlackPropertyRestorer() = delete;
    explicit RedBlackPropertyRestorer(NodePointer<T> nodeZ);
    void restore();
private:
    NodePointer<T> nodeZ;
    NodePointer<T> zParent;
    Side parentSide;
    Side getChildSide(NodePointer<T> child);
    bool zHasRedUncle();
    bool zIsSentinel();
    void moveRednessUpFromZParentAndUncle();
    void moveRednessFromParentUp();
    void restoreFromZGrandpaUp();
    bool zIsSameSideAsFather();
    void rotateZParent();
    void restoreFromParentUp();
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
    if(!(zParent->isRed()) || zIsSentinel())
    {
        return;
    }
    else if(zHasRedUncle())
    {
        moveRednessUpFromZParentAndUncle();
        restoreFromZGrandpaUp();
        return;
    }
    else if(zIsSameSideAsFather())
    {
        rotateZParent();
        restoreFromParentUp();
        return;
    }
    else
    {
        moveRednessFromParentUp();
        rotateZParent();
    }
}

template<typename T>
Side RedBlackPropertyRestorer<T>::getChildSide(NodePointer<T> child)
{
    return (child->isRightChild() ? Side::RIGHT : Side::LEFT);
}

template<typename T>
bool RedBlackPropertyRestorer<T>::zHasRedUncle()
{
    return nodeZ->uncleIsRed();
}

template<typename T>
bool RedBlackPropertyRestorer<T>::zIsSentinel()
{
    return !nodeZ->isChild();
}

template<typename T>
void RedBlackPropertyRestorer<T>::moveRednessUpFromZParentAndUncle()
{
    moveRednessFromParentUp();
    zParent->getSibling()->paintBlack();
}

template<typename T>
void RedBlackPropertyRestorer<T>::restoreFromZGrandpaUp()
{
    auto restorer = RedBlackPropertyRestorer<T>(zParent->getParent());
    restorer.restore();
}

template<typename T>
bool RedBlackPropertyRestorer<T>::zIsSameSideAsFather()
{
    return parentSide != getChildSide(nodeZ);
}

template<typename T>
void RedBlackPropertyRestorer<T>::rotateZParent()
{
    nodeZ->rotateParent();
}

template<typename T>
void RedBlackPropertyRestorer<T>::restoreFromParentUp()
{
    auto restorer = RedBlackPropertyRestorer<T>(zParent);
    restorer.restore();
}

template<typename T>
void RedBlackPropertyRestorer<T>::moveRednessFromParentUp() {
    zParent->paintBlack();
    zParent->getParent()->paintRed();
}

#endif //SDIZO_1_REDBLACKPROPERTYRESTORER_H
