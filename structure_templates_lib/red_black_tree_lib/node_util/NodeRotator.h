#ifndef SDIZO_1_NODEROTATOR_H
#define SDIZO_1_NODEROTATOR_H

#include "NodeUtility.h"
#include "red_black_tree_lib/nodes/Node.h"

template <typename T, typename U>
class NodeRotator : public NodeUtility<T, U>
{
public:
    void rotateRight(NodePointer<T, U> nodeToRotate);
    void rotateLeft(NodePointer<T, U> nodeToRotate);
    void rotate(NodePointer<T, U> node, Side rotationDirection);
private:
    void rotate(NodePointer<T, U> nodeToRotate);

    Side direction;
    NodePointer<T, U> nodeToRotate;
};

template<typename T, typename U>
void NodeRotator<T, U>::rotateRight(NodePointer<T, U> node) {
    rotate(node, Side::RIGHT);
}

template<typename T, typename U>
void NodeRotator<T, U>::rotateLeft(NodePointer<T, U> node) {
    rotate(node, Side::LEFT);
}

template<typename T, typename U>
void NodeRotator<T, U>::rotate(NodePointer<T, U> node) {
    this->nodeToRotate = node;
    auto child = nodeToRotate->get(!direction);
    auto parent = nodeToRotate->getParent();
    child->setParent(parent);
    if(nodeToRotate->getKey() < parent->getKey())
        parent->setLeft(child);
    else
        parent->setRight(child);
    auto buffer = child->get(direction);
    child->setSide(nodeToRotate, direction);
    nodeToRotate->setSide(buffer, !direction);
    buffer->setParent(nodeToRotate);
    nodeToRotate->setParent(child);
    currentNode = nodeToRotate;
}

template<typename T, typename U>
void NodeRotator<T, U>::rotate(NodePointer<T, U> node, Side rotationDirection) {
    this->direction = rotationDirection;
    rotate(node);
}

#endif //SDIZO_1_NODEROTATOR_H
