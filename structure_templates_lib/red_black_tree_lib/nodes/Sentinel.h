#ifndef SDIZO_1_SENTINEL_H
#define SDIZO_1_SENTINEL_H

#include "Node.h"

template <typename T, typename U>
class Sentinel : public Node<T, U>
{
public:
    U& getContent();
    T getKey();
    void setParent(NodePointer<T, U>);
    NodePointer<T, U> getParent();
    void setLeft(NodePointer<T, U>) override;
    NodePointer<T, U> getLeft() override;
    void setRight(NodePointer<T, U>) override;
    NodePointer<T, U> getRight() override;
    bool isNil() override;

    static NodePointer<T, U> getInstance();
private:
    static U content;
    static T key;
    static NodePointer<T, U> instance;
};

template <typename T, typename U>
NodePointer<T,U> Sentinel<T, U>::instance = NodePointer<T, U>(new Sentinel<T, U>());

template <typename T, typename U>
U Sentinel<T, U>::content = NULL;

template <typename T, typename U>
T Sentinel<T, U>::key = NULL;

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getParent() {
    return getInstance();
}

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getLeft() {
    return getInstance();
}

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getRight() {
    return getInstance();
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

template<typename T, typename U>
void Sentinel<T, U>::setLeft(NodePointer<T, U>) {
    //nil z definicji jest bezdzietny
}

template<typename T, typename U>
void Sentinel<T, U>::setRight(NodePointer<T, U>) {
    //nil z definicji jest bezdzietny
}

template<typename T, typename U>
void Sentinel<T, U>::setParent(NodePointer<T, U> parent) {

}

template<typename T, typename U>
NodePointer<T, U> Sentinel<T, U>::getInstance() {
    return instance;
}

#endif //SDIZO_1_SENTINEL_H
