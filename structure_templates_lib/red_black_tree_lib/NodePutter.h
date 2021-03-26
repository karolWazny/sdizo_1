#ifndef SDIZO_1_NODEPUTTER_H
#define SDIZO_1_NODEPUTTER_H

#include "Node.h"
#include "PlaceToPutFinder.h"
#include "NodeFactory.h"
#include "RootFinder.h"

template <typename T, typename U>
class NodePutter
{
public:
    explicit NodePutter(NodePointer<T, U> root);
    void put(T, U);
    NodePointer<T, U> getRoot();
private:
    NodePointer<T, U> currentNode;
    NodePointer<T, U> root;
    Side sideOfPlaceToPut;
};

template<typename T, typename U>
NodePutter<T, U>::NodePutter(NodePointer<T, U> root) {
    this->root = root;
}

template<typename T, typename U>
void NodePutter<T, U>::put(T key, U value) {
    currentNode = root;
    auto finder = PlaceToPutFinder<T, U>(root);
    finder.setKeyToBePut(key);
    finder.find();
    sideOfPlaceToPut = finder.getPlaceSide();
    currentNode = finder.getFound();
    auto nodeToBePut = NodeFactory<T, U>::makeNode(key, value);
    if(sideOfPlaceToPut == Side::LEFT)
    {
        currentNode->setLeft(nodeToBePut);
    }
    else
    {
        currentNode->setRight(nodeToBePut);
    }
    nodeToBePut->setParent(currentNode);
    auto rootFinder = RootFinder<T, U>(nodeToBePut);
    rootFinder.find();
    root = rootFinder.getFound();
}

template<typename T, typename U>
NodePointer<T, U> NodePutter<T, U>::getRoot() {
    return root;
}

#endif //SDIZO_1_NODEPUTTER_H
