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
    Side nodeToReplaceSide= Side::RIGHT;
    if(parent->getKey() > currentNode->getKey())
    {
        nodeToReplaceSide = Side::LEFT;
    }
    if(!parent->isNil())
    {
        parent->setSide(replacement, nodeToReplaceSide);
    }
    replacement->setParent(parent);

    if(!replacement->isNil())
    {
        auto left = currentNode->getLeft();
        replacement->setLeft(left);
        left->setParent(replacement);//todo tu się coś chrzani

        auto right = currentNode->getRight();
        replacement->setRight(right);
        right->setParent(replacement);

        currentNode = replacement;
    }
}

#endif //SDIZO_1_NODEREPLACER_H
