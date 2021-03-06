#ifndef SDIZO_1_NODEFACTORY_H
#define SDIZO_1_NODEFACTORY_H

#include "Node.h"

template <typename T, typename U>
class NodeFactory
{
public:
    virtual NodePointer<T, U> createNode(T, U) = 0;

    virtual NodePointer<T, U> createSentinel(T, U) = 0;

    virtual NodePointer<T, U> createSentinel(void) = 0;
};

#endif //SDIZO_1_NODEFACTORY_H
