#ifndef SDIZO_1_NODEREPLACER_H
#define SDIZO_1_NODEREPLACER_H

#include "red_black_tree_lib/nodes/Node.h"
#include "Side.h"
#include "NodeUtility.h"

template <typename T, typename U>
class NodeReplacer : public NodeUtility<T, U>
{
public:
    explicit NodeReplacer(NodePointer<T, U> nodeToReplace);
    void replaceWithNode(NodePointer<T, U> replacementNode);
private:
    void replace();

    NodePointer<T, U> replacement;
};

template<typename T, typename U>
NodeReplacer<T, U>::NodeReplacer(NodePointer<T, U> nodeToReplace) {
    this->currentNode = nodeToReplace;
}

template<typename T, typename U>
void NodeReplacer<T, U>::replaceWithNode(NodePointer<T, U> replacementNode) {
    this->replacement = replacementNode;
    replace();
}

template<typename T, typename U>
void NodeReplacer<T, U>::replace() {
    auto parent = currentNode->getParent();
    Side nodeToReplaceSide;
    if(parent->getKey() > currentNode->getKey())
    {
        nodeToReplaceSide = Side::LEFT;
    }
    else
    {
        nodeToReplaceSide = Side::RIGHT;
    }
    if(nodeToReplaceSide == Side::LEFT)
    {
        parent->setLeft(replacement);
    }
    else
    {
        parent->setRight(replacement);
    }
    replacement->setParent(parent);

    auto left = currentNode->getLeft();
    replacement->setLeft(left);
    left->setParent(replacement);

    auto right = currentNode->getRight();
    replacement->setRight(right);
    right->setParent(replacement);

    //if(!replacement->isNil())//todo nie wiem, czy to rozwiązuje problem, na razie zostawię zakomentowane
    currentNode = replacement;
}

#endif //SDIZO_1_NODEREPLACER_H
