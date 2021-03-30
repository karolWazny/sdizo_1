#ifndef SDIZO_1_SIMPLEFACTORY_H
#define SDIZO_1_SIMPLEFACTORY_H

#include "Node.h"
#include "NodeImpl.h"
#include "Sentinel.h"

#include "NodeFactory.h"

//todo rozwiązać zależność cykliczną

template <typename T, typename U>
class SimpleFactory : public NodeFactory<T, U>
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
NodePointer<T, U> SimpleFactory<T, U>::makeNode(T key, U value) {
    return NodePointer<T, U>(new NodeImpl<T, U>(key, value));
}

template<typename T, typename U>
NodePointer<T, U> SimpleFactory<T, U>::makeSentinel(void) {
    return Sentinel<T, U>::getInstance();
}

template<typename T, typename U>
NodePointer<T, U> SimpleFactory<T, U>::makeSentinel(T, U) {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> SimpleFactory<T, U>::createNode(T key, U value) {
    return makeNode(key, value);
}

template<typename T, typename U>
NodePointer<T, U> SimpleFactory<T, U>::createSentinel(T key, U value) {
    return makeSentinel(); //todo do poprawy
}

template<typename T, typename U>
NodePointer<T, U> SimpleFactory<T, U>::createSentinel(void) {
    return makeSentinel();
}

#endif //SDIZO_1_SIMPLEFACTORY_H
