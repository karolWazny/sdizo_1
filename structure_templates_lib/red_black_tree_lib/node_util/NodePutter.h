#ifndef SDIZO_1_NODEPUTTER_H
#define SDIZO_1_NODEPUTTER_H

#include "red_black_tree_lib/nodes/Node.h"
#include "PlaceToPutFinder.h"
#include "red_black_tree_lib/nodes/SimpleFactory.h"
#include "red_black_tree_lib/nodes/NodeFactory.h"
#include "NodeUtility.h"

template <typename T, typename U>
class NodePutter : public NodeUtility<T, U>
{
public:
    explicit NodePutter(NodePointer<T, U> root, NodeFactory<T, U>* nodeFactory);
    explicit NodePutter(NodePointer<T, U> root);
    void put(T, U);
    NodePointer<T, U> getFreshNode();
private:
    NodePointer<T, U> root;
    NodePointer<T, U> freshNode;
    Side sideOfPlaceToPut;
    std::unique_ptr<NodeFactory<T, U>> factory;
};

template<typename T, typename U>
NodePutter<T, U>::NodePutter(NodePointer<T, U> root, NodeFactory<T, U>* nodeFactory) {
    this->root = root;
    this->factory = std::unique_ptr<NodeFactory<T, U>>(nodeFactory);
}


template<typename T, typename U>
NodePutter<T, U>::NodePutter(NodePointer<T, U> root) {
    this->root = root;
    this->factory = std::unique_ptr<NodeFactory<T, U>>(new SimpleFactory<T, U>());
}

template<typename T, typename U>
void NodePutter<T, U>::put(T key, U value) {
    currentNode = root;
    auto finder = PlaceToPutFinder<T, U>(root);
    finder.setKeyToBePut(key);
    finder.find();
    sideOfPlaceToPut = finder.getPlaceSide();
    currentNode = finder.getFound();
    freshNode = factory->createNode(key, value);
    currentNode->setSide(freshNode, sideOfPlaceToPut);
    if(!currentNode->isNil())
        freshNode->setParent(currentNode);
    currentNode = freshNode;
}

template<typename T, typename U>
NodePointer<T, U> NodePutter<T, U>::getFreshNode() {
    return freshNode;
}


#endif //SDIZO_1_NODEPUTTER_H
