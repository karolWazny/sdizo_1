#ifndef SDIZO_1_CONSEQUENTFINDER_H
#define SDIZO_1_CONSEQUENTFINDER_H

#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/NodeFinder.h"

template <typename T, typename U>
class ConsequentFinder : public NodeFinder<T, U>
{
public:
    explicit ConsequentFinder(NodePointer<T, U> initialNode);

    NodePointer<T, U> find();
    NodePointer<T, U> getFound();
    bool nodeFound();
    Side getConsequentSide();

private:
    NodePointer<T, U> obtainCurrentChildOnTheSide(Side side);

    NodePointer<T, U> currentNode;
    Side consequentSide;
    bool nodeWasFound;
};

template<typename T, typename U>
ConsequentFinder<T, U>::ConsequentFinder(NodePointer<T, U> initialNode) {
    currentNode = initialNode;
}

template<typename T, typename U>
NodePointer<T, U> ConsequentFinder<T, U>::find() {
    auto buffer = currentNode->getRight();
    consequentSide = Side::RIGHT;
    if(buffer->isNil())
    {
        consequentSide = Side::LEFT;
        buffer = currentNode->getLeft();
    }
    if(buffer->isNil())
    {
        currentNode = buffer;
    }
    while(!buffer->isNil())
    {
        currentNode = buffer;
        buffer = obtainCurrentChildOnTheSide(!consequentSide);
    }
    return currentNode;
}

template<typename T, typename U>
NodePointer<T, U> ConsequentFinder<T, U>::obtainCurrentChildOnTheSide(Side side) {
    return (side == Side::LEFT ? currentNode->getLeft() : currentNode->getRight());
}

template<typename T, typename U>
NodePointer<T, U> ConsequentFinder<T, U>::getFound() {
    return currentNode;
}

template<typename T, typename U>
bool ConsequentFinder<T, U>::nodeFound() {
    return nodeWasFound;
}

template<typename T, typename U>
Side ConsequentFinder<T, U>::getConsequentSide() {
    return consequentSide;
}

#endif //SDIZO_1_CONSEQUENTFINDER_H
