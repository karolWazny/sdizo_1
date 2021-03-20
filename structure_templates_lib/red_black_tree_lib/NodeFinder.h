//
// Created by admin on 21.03.2021.
//

#ifndef SDIZO_1_NODEFINDER_H
#define SDIZO_1_NODEFINDER_H

#include "Node.h"

template <typename T, typename U>
class NodeFinder
{
public:
    NodePointer<T, U> find() = 0;
    NodePointer<T, U> getFound() = 0;
    bool nodeFound() = 0;
};

#endif //SDIZO_1_NODEFINDER_H
