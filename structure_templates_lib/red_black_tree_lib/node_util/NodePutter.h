#ifndef SDIZO_1_NODEPUTTER_H
#define SDIZO_1_NODEPUTTER_H

#include "red_black_tree_lib/nodes/Node.h"
#include "PlaceToPutFinder.h"
#include "red_black_tree_lib/nodes/NodeFactory.h"
#include "NodeUtility.h"

template <typename T, typename U>
class NodePutter : public NodeUtility<T, U>
{
public:
    explicit NodePutter(NodePointer<T, U> root, NodeFactory<T, U> nodeFactory);
    explicit NodePutter(NodePointer<T, U> root);
    void put(T, U);
private:
    NodePointer<T, U> root;
    Side sideOfPlaceToPut;
    NodeFactory<T, U> factory;
};

template<typename T, typename U>
NodePutter<T, U>::NodePutter(NodePointer<T, U> root, NodeFactory<T, U> nodeFactory) {
    this->root = root;
    this->factory = nodeFactory;
}


template<typename T, typename U>
NodePutter<T, U>::NodePutter(NodePointer<T, U> root) {
    this->root = root;
    this->factory = NodeFactory<T, U>();
}

template<typename T, typename U>
void NodePutter<T, U>::put(T key, U value) {
    currentNode = root;
    auto finder = PlaceToPutFinder<T, U>(root);
    finder.setKeyToBePut(key);
    finder.find();
    sideOfPlaceToPut = finder.getPlaceSide();
    currentNode = finder.getFound();
    auto nodeToBePut = factory.createNode(key, value);
    if(sideOfPlaceToPut == Side::LEFT)
    {
        currentNode->setLeft(nodeToBePut);
    }
    else
    {
        currentNode->setRight(nodeToBePut);
    }
    nodeToBePut->setParent(currentNode);
    currentNode = nodeToBePut;
}


#endif //SDIZO_1_NODEPUTTER_H
