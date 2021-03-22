#ifndef SDIZO_1_PLACETOPUTFINDER_H
#define SDIZO_1_PLACETOPUTFINDER_H

#include "NodeFinder.h"
#include "Side.h"


template <typename T, typename U>
class PlaceToPutFinder : public NodeFinder<T, U>
{
public:
    explicit PlaceToPutFinder(NodePointer<T, U> initialNode);
    NodePointer<T, U> find();
    NodePointer<T, U> getFound();
    bool nodeFound();

    void setKeyToBePut(T key);
    Side getPlaceSide();

private:
    bool nodeWasFound;
    NodePointer<T, U> currentNode;
    T currentNodeKey;
    NodePointer<T, U> currentChild;
    Side currentChildSide;
    T keyToBePut;
};

template<typename T, typename U>
PlaceToPutFinder<T, U>::PlaceToPutFinder(NodePointer<T, U> initialNode) {
    currentNode = initialNode;
    nodeWasFound = false;
}

template<typename T, typename U>
void PlaceToPutFinder<T, U>::setKeyToBePut(T key) {
    keyToBePut = key;
}

template<typename T, typename U>
NodePointer<T, U> PlaceToPutFinder<T, U>::find() {
    currentNodeKey = currentNode->getKey();
    if(currentNodeKey > keyToBePut)
    {
        currentChild = currentNode->getLeft();
        currentChildSide = Side::LEFT;
    }
    else
    {
        currentChild = currentNode->getRight();
        currentChildSide = Side::RIGHT;
    }
    while(!currentChild->isNil()){
        currentNode = currentChild;
        currentNodeKey = currentNode->getKey();
        if(currentNodeKey > keyToBePut)
        {
            currentChild = currentNode->getLeft();
            currentChildSide = Side::LEFT;
        }
        else
        {
            currentChild = currentNode->getRight();
            currentChildSide = Side::RIGHT;
        }
    }
    nodeWasFound = true;
    return currentNode;
}

template<typename T, typename U>
NodePointer<T, U> PlaceToPutFinder<T, U>::getFound() {
    return currentNode;
}

template<typename T, typename U>
bool PlaceToPutFinder<T, U>::nodeFound() {
    return nodeWasFound;
}

template<typename T, typename U>
Side PlaceToPutFinder<T, U>::getPlaceSide() {
    return currentChildSide;
}

#endif //SDIZO_1_PLACETOPUTFINDER_H
