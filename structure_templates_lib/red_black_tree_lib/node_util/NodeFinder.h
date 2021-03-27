//
// Created by admin on 21.03.2021.
//

#ifndef SDIZO_1_NODEFINDER_H
#define SDIZO_1_NODEFINDER_H

#include "red_black_tree_lib/nodes/Node.h"

template <typename T, typename U>
class NodeFinder
{
public:
    virtual NodePointer<T, U> find() = 0;
    virtual NodePointer<T, U> getFound() = 0;
    virtual bool nodeFound() = 0;
};

#endif //SDIZO_1_NODEFINDER_H
