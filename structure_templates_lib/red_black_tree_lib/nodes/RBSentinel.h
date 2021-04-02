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
    RBSentinel(NodePointer<T, U>& node);

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

    int checkAmountOfBlackToLeaves() override;

    static RBNodePtr<T, U> getInstance();

private:
    static U content;
    static T key;
    Black black;

    NodePointer<T, U>& parent;

    NodePointer<T, U> parentPointer;

    static NodePointer<T, U> instance;
};

template <typename T, typename U>
NodePointer<T,U> RBSentinel<T, U>::instance = RBNodePtr<T, U>(new RBSentinel<T, U>());

template <typename T, typename U>
U RBSentinel<T, U>::content = NULL;

template <typename T, typename U>
T RBSentinel<T, U>::key = NULL;

template<typename T, typename U>
RBSentinel<T, U>::RBSentinel(NodePointer<T, U>& node):parent(parentPointer) {
    this->black = Black();
    parent = node;
}

template<typename T, typename U>
RBSentinel<T, U>::RBSentinel():parent(instance) {
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
void RBSentinel<T, U>::setParent(NodePointer<T, U> node) {
    if(parent != instance)
        parent = node;
}

template<typename T, typename U>
NodePointer<T, U> RBSentinel<T, U>::getParent() {
    return parent;
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
    return rbcast(instance);
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

template<typename T, typename U>
int RBSentinel<T, U>::checkAmountOfBlackToLeaves() {
    return 1;
}

#endif //SDIZO_1_RBSENTINEL_H
