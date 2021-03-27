#ifndef SDIZO_1_KEYFINDER_H
#define SDIZO_1_KEYFINDER_H

#include "red_black_tree_lib/node_util/NodeFinder.h"

template <typename T, typename U>
class KeyFinder : public NodeFinder<T, U>
{
public:
    KeyFinder(NodePointer<T, U> startingNode);
    void setDesiredKey(T key);

    NodePointer<T, U> find() override;
    NodePointer<T, U> getFound() override;
    bool nodeFound() override;
private:
    NodePointer<T, U> currentNode;
    T currentKey;
    T desiredKey;
    bool nodeWasFound;
};

template<typename T, typename U>
KeyFinder<T, U>::KeyFinder(NodePointer<T, U> startingNode) {
    this->currentNode = startingNode;
    nodeWasFound = false;
}


template<typename T, typename U>
void KeyFinder<T, U>::setDesiredKey(T key) {
    this->desiredKey = key;
}

template<typename T, typename U>
NodePointer<T, U> KeyFinder<T, U>::find() {
    while(!currentNode->isNil())
    {
        currentKey = currentNode->getKey();
        if(currentKey == desiredKey)
        {
            nodeWasFound = true;
            break;
        }
        else if(currentKey > desiredKey)
        {
            currentNode = currentNode->getLeft();
            continue;
        }
        else
            currentNode = currentNode->getRight();
    }

    return currentNode;
}

template<typename T, typename U>
NodePointer<T, U> KeyFinder<T, U>::getFound() {
    return currentNode;
}

template<typename T, typename U>
bool KeyFinder<T, U>::nodeFound() {
    return nodeWasFound;
}

#endif //SDIZO_1_KEYFINDER_H
