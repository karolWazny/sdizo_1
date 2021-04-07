#ifndef SDIZO_1_RBPUTTER_H
#define SDIZO_1_RBPUTTER_H

#include <red_black_tree_lib/nodes/RBFactory.h>
#include "red_black_tree_lib/node_util/NodePutter.h"
#include "red_black_tree_lib/rbutil/PutPropertyRestorer.h"

template <typename T>
class RBPutter : public NodeUtility<T>
{
public:
    explicit RBPutter(NodePointer<T> root);
    void put(T);
private:
    NodePointer<T> root;
};

template<typename T>
RBPutter<T>::RBPutter(NodePointer<T> root) {
    this->root = root;
}

template<typename T>
void RBPutter<T>::put(T key) {
    auto putter = NodePutter<T>(root, new RBFactory<T>());
    putter.put(key);
    auto freshNode = rbcast(putter.getFreshNode());
    auto restorer = PutPropertyRestorer<T>();
    restorer.restoreFrom(freshNode);//todo tutaj siedzi diabeł
    currentNode = restorer.obtainRoot();
}

#endif //SDIZO_1_RBPUTTER_H
