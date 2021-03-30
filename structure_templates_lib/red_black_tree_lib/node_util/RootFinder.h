#ifndef SDIZO_1_ROOTFINDER_H
#define SDIZO_1_ROOTFINDER_H

#include "red_black_tree_lib/node_util/NodeFinder.h"

template <typename T, typename U>
class RootFinder
{
public:
    explicit RootFinder(NodePointer<T, U> initialNode);

    NodePointer<T, U> find();
    NodePointer<T, U> getFound();
    bool nodeFound();
private:
    bool nodeWasFound;
    NodePointer<T, U> currentNode;
};

template<typename T, typename U>
RootFinder<T, U>::RootFinder(NodePointer<T, U> initialNode) {
    currentNode = initialNode;
    nodeWasFound = false;
}

template<typename T, typename U>
NodePointer<T, U> RootFinder<T, U>::find() {
    auto temp = currentNode->getParent();
    while(!temp->isNil())
    {
        currentNode = temp;
        temp = currentNode->getParent();
    }
    nodeWasFound = true;
    return getFound();
}

template<typename T, typename U>
NodePointer<T, U> RootFinder<T, U>::getFound() {
    return currentNode;
}

template<typename T, typename U>
bool RootFinder<T, U>::nodeFound() {
    return nodeWasFound;
}

#endif //SDIZO_1_ROOTFINDER_H
