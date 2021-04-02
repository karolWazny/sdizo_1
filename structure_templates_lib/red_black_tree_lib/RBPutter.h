#ifndef SDIZO_1_RBPUTTER_H
#define SDIZO_1_RBPUTTER_H

#include <red_black_tree_lib/nodes/RBFactory.h>
#include "red_black_tree_lib/node_util/NodePutter.h"
#include "red_black_tree_lib/rbutil/PutPropertyRestorer.h"

template <typename T, typename U>
class RBPutter : public NodeUtility<T, U>
{
public:
    explicit RBPutter(NodePointer<T, U> root);
    void put(T, U);
private:
    NodePointer<T, U> root;
};

template<typename T, typename U>
RBPutter<T, U>::RBPutter(NodePointer<T, U> root) {
    this->root = root;
}

template<typename T, typename U>
void RBPutter<T, U>::put(T key, U value) {
    auto putter = NodePutter<T, U>(root, new RBFactory<T, U>());
    putter.put(key, value);
    auto freshNode = rbcast(putter.getFreshNode());
    auto restorer = PutPropertyRestorer<T, U>();
    restorer.restoreFrom(freshNode);//todo tutaj siedzi diabeł
    currentNode = restorer.obtainRoot();
}

#endif //SDIZO_1_RBPUTTER_H
