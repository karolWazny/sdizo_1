#ifndef SDIZO_1_CONSEQUENTLIBERATOR_H
#define SDIZO_1_CONSEQUENTLIBERATOR_H

#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/NodeUtility.h"
#include "Side.h"


template <typename T, typename U>
class ConsequentLiberator : public NodeUtility<T, U>
{
public:
    explicit ConsequentLiberator(NodePointer<T, U> root);
    void free(NodePointer<T, U> node);
    NodePointer<T, U> getFreed();
private:
    NodePointer<T, U> nodeToFree;
};

template<typename T, typename U>
ConsequentLiberator<T, U>::ConsequentLiberator(NodePointer<T, U> root) {
    currentNode = root;
}

template<typename T, typename U>
void ConsequentLiberator<T, U>::free(NodePointer<T, U> node){
    nodeToFree = node;
    auto parent = nodeToFree->getParent();
    Side consequentSide = Side::LEFT;
    if(parent->getKey() > nodeToFree->getKey())
        consequentSide = Side::RIGHT;
    auto child = nodeToFree->get(consequentSide);
    if(child->isNil())
        child = nodeToFree->get(!consequentSide);
    child->setParent(parent);
    parent->setSide(child, !consequentSide);
    if(currentNode == nodeToFree)
        currentNode = child;
}

template<typename T, typename U>
NodePointer<T, U> ConsequentLiberator<T, U>::getFreed() {
    return nodeToFree;
}

#endif //SDIZO_1_CONSEQUENTLIBERATOR_H
