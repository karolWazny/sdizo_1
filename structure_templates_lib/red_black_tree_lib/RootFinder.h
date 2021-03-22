#ifndef SDIZO_1_ROOTFINDER_H
#define SDIZO_1_ROOTFINDER_H

#include "NodeFinder.h"

template <typename T, typename U>
class RootFinder
{
public:
    RootFinder(NodePointer<T, U> initialNode);

    NodePointer<T, U> find();
    NodePointer<T, U> getFound();
    bool nodeFound();
private:
    bool nodeWasFound;
};

#endif //SDIZO_1_ROOTFINDER_H
