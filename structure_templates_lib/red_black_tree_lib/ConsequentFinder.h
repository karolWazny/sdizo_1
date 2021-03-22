#ifndef SDIZO_1_CONSEQUENTFINDER_H
#define SDIZO_1_CONSEQUENTFINDER_H

#include "Node.h"
#include "NodeFinder.h"

template <typename T, typename U>
class ConsequentFinder : public NodeFinder<T, U>
{
public:
    explicit ConsequentFinder(NodePointer<T, U> initialNode);

    NodePointer<T, U> find();
    NodePointer<T, U> getFound();
    bool nodeFound();
};

template<typename T, typename U>
ConsequentFinder<T, U>::ConsequentFinder(NodePointer<T, U> initialNode) {

}

template<typename T, typename U>
NodePointer<T, U> ConsequentFinder<T, U>::find() {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> ConsequentFinder<T, U>::getFound() {
    return NodePointer<T, U>();
}

template<typename T, typename U>
bool ConsequentFinder<T, U>::nodeFound() {
    return false;
}

#endif //SDIZO_1_CONSEQUENTFINDER_H
