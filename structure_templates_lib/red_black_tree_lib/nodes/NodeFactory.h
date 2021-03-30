#ifndef SDIZO_1_NODEFACTORY_H
#define SDIZO_1_NODEFACTORY_H

#include "Node.h"
#include "NodeImpl.h"
#include "Sentinel.h"

#include "RBNodeImpl.h"
#include "red_black_tree_lib/colors/RedBlack.h"

//todo rozwiązać zależność cykliczną

template <typename T, typename U>
class NodeFactory
{
public:
    static NodePointer<T, U> makeNode(T, U);
    static NodePointer<T, U> makeSentinel(T, U);
    static NodePointer<T, U> makeSentinel(void);

    NodePointer<T, U> createNode(T, U);
    NodePointer<T, U> createSentinel(T, U);
    NodePointer<T, U> createSentinel(void);
};

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeNode(T key, U value) {
    return NodePointer<T, U>(new NodeImpl<T, U>(key, value));
    //return NodePointer<T, U>(new RBNodeImpl<T, U>(new NodeImpl<T, U>(key, value), new RedBlack()));
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeSentinel(void) {
    return Sentinel<T, U>::getInstance();
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::makeSentinel(T, U) {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::createNode(T key, U value) {
    return makeNode(key, value);
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::createSentinel(T key, U value) {
    return makeSentinel(); //todo do poprawy
}

template<typename T, typename U>
NodePointer<T, U> NodeFactory<T, U>::createSentinel(void) {
    return makeSentinel();
}

#endif //SDIZO_1_NODEFACTORY_H
