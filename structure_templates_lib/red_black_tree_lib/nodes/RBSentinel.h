#ifndef SDIZO_1_RBSENTINEL_H
#define SDIZO_1_RBSENTINEL_H

#include "RBNode.h"
#include "Sentinel.h"
#include "red_black_tree_lib/colors/Black.h"

template <typename T, typename U>
class RBSentinel : public RBNode<T, U>
{
public:
    RBSentinel();

    virtual U& getContent();
    virtual T getKey();
    virtual void setParent(NodePointer<T, U>);
    virtual NodePointer<T, U> getParent();
    virtual void setLeft(NodePointer<T, U>);
    virtual NodePointer<T, U> getLeft();
    virtual void setRight(NodePointer<T, U>);
    virtual NodePointer<T, U> getRight();
    virtual bool isNil();

    virtual bool isBlack();
    virtual bool isRed();
    virtual void paintBlack();
    virtual void paintRed();

    static RBNodePtr<T, U> getInstance();

private:
    static U content;
    static T key;
    Black black;

    static RBNodePtr<T, U> instance;
};

template <typename T, typename U>
RBNodePtr<T,U> RBSentinel<T, U>::instance = RBNodePtr<T, U>(new RBSentinel<T, U>());

template <typename T, typename U>
U RBSentinel<T, U>::content = NULL;

template <typename T, typename U>
T RBSentinel<T, U>::key = NULL;


template<typename T, typename U>
RBSentinel<T, U>::RBSentinel() {
    this->black = Black();
}

template<typename T, typename U>
U &RBSentinel<T, U>::getContent() {
    return content;
}

template<typename T, typename U>
T RBSentinel<T, U>::getKey() {
    return key;
}

template<typename T, typename U>
void RBSentinel<T, U>::setParent(NodePointer<T, U>) {

}

template<typename T, typename U>
NodePointer<T, U> RBSentinel<T, U>::getParent() {
    return getInstance();
}

template<typename T, typename U>
void RBSentinel<T, U>::setLeft(NodePointer<T, U>) {

}

template<typename T, typename U>
NodePointer<T, U> RBSentinel<T, U>::getLeft() {
    return getInstance();
}

template<typename T, typename U>
void RBSentinel<T, U>::setRight(NodePointer<T, U>) {

}

template<typename T, typename U>
NodePointer<T, U> RBSentinel<T, U>::getRight() {
    return getInstance();
}

template<typename T, typename U>
bool RBSentinel<T, U>::isNil() {
    return true;
}

template<typename T, typename U>
RBNodePtr<T, U> RBSentinel<T, U>::getInstance() {
    return instance;
}

template<typename T, typename U>
bool RBSentinel<T, U>::isBlack() {
    return black.isBlack();
}

template<typename T, typename U>
bool RBSentinel<T, U>::isRed() {
    return black.isRed();
}

template<typename T, typename U>
void RBSentinel<T, U>::paintBlack() {
    black.paintBlack();
}

template<typename T, typename U>
void RBSentinel<T, U>::paintRed() {
    black.paintRed();
}


#endif //SDIZO_1_RBSENTINEL_H
