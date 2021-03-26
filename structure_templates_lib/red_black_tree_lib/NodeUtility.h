#ifndef SDIZO_1_NODEUTILITY_H
#define SDIZO_1_NODEUTILITY_H

#include "Node.h"
#include "RootFinder.h"

template <typename T, typename U>
class NodeUtility
{
public:
    NodePointer<T, U> obtainRoot();
protected:
    NodePointer<T, U> currentNode;
};

template<typename T, typename U>
NodePointer<T, U> NodeUtility<T, U>::obtainRoot(){
    auto rootFinder = RootFinder<T, U>(currentNode);
    rootFinder.find();
    return rootFinder.getFound();
}

#endif //SDIZO_1_NODEUTILITY_H
