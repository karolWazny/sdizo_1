#ifndef SDIZO_1_NODEFACTORY_H
#define SDIZO_1_NODEFACTORY_H

#include "Node.h"
#include "NodeImpl.h"
#include "Sentinel.h"

//todo rozwiązać zależność cykliczną

template <typename T, typename U>
class NodeFactory
{
public:
    static NodePointer<T, U> makeNode(T, U);
    static NodePointer<T, U> makeSentinel(T, U);
    static NodePointer<T, U> makeSentinel(void);
};

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeNode(T key, U value) {
    return NodePointer<T, U>(new NodeImpl<T, U>(key, value));
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeSentinel(void) {
    return Sentinel<T, U>::getInstance();
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeSentinel(T, U) {
    return NodePointer<T, U>();
}

#endif //SDIZO_1_NODEFACTORY_H
