//
// Created by admin on 19.03.2021.
//

#ifndef SDIZO_1_SENTINEL_H
#define SDIZO_1_SENTINEL_H

#include "Node.h"

template <typename T, typename U>
class Sentinel : public Node<T, U>
{
public:
    U& getContent();
    T getKey();
    NodePointer<T, U> getParent();
    NodePointer<T, U> getLeft();
    NodePointer<T, U> getRight();
    bool isNil() override;
private:
    static U content;
    static T key;
};

template <typename T, typename U>
U Sentinel<T, U>::content = NULL;

template <typename T, typename U>
T Sentinel<T, U>::key = NULL;

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getParent() {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getLeft() {
    return NodePointer<T, U>();
}

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getRight() {
    return NodePointer<T, U>();
}

template<typename T, typename U>
U &Sentinel<T, U>::getContent() {
    return content;
}

template<typename T, typename U>
T Sentinel<T, U>::getKey() {
    return key;
}

template<typename T, typename U>
bool Sentinel<T, U>::isNil() {
    return true;
}

#endif //SDIZO_1_SENTINEL_H
