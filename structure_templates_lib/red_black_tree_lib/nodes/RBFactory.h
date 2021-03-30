#ifndef SDIZO_1_RBFACTORY_H
#define SDIZO_1_RBFACTORY_H

#include "Node.h"
#include "NodeImpl.h"
#include "RBSentinel.h"
#include "RBNodeImpl.h"
#include "red_black_tree_lib/colors/RedBlack.h"

#include "NodeFactory.h"

template <typename T, typename U>
class RBFactory : public NodeFactory<T, U>
{
public:
    static NodePointer<T, U> makeNode(T, U);
    static NodePointer<T, U> makeSentinel(T, U);
    static NodePointer<T, U> makeSentinel(void);

    NodePointer<T, U> createNode(T, U) override;
    NodePointer<T, U> createSentinel(T, U) override;
    NodePointer<T, U> createSentinel(void) override;
};

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::makeNode(T key, U value) {
    return NodePointer<T, U>(new RBNodeImpl<T, U>(new NodeImpl<T, U>(key, value), new RedBlack()));
}

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::makeSentinel(void) {
    return RBSentinel<T, U>::getInstance();
}

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::makeSentinel(T, U) {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::createNode(T key, U value) {
    return makeNode(key, value);
}

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::createSentinel(T key, U value) {
    return makeSentinel(); //todo do poprawy
}

template<typename T, typename U>
NodePointer<T, U> RBFactory<T, U>::createSentinel(void) {
    return makeSentinel();
}

#endif //SDIZO_1_RBFACTORY_H
