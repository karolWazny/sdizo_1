#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/KeyFinder.h"
#include "red_black_tree_lib/node_util/NodePutter.h"
#include "red_black_tree_lib/node_util/ConsequentFinder.h"
#include "red_black_tree_lib/node_util/ConsequentLiberator.h"
#include "red_black_tree_lib/node_util/NodeReplacer.h"
#include "red_black_tree_lib/nodes/RBFactory.h"
#include "RBPutter.h"
#include "RBRemover.h"

template <typename T, typename U>
class RedBlackTree
{
public:
    RedBlackTree();
    void put(T key, U value);
    bool containsKey(T key);
    bool containsValue(U value);
    void removeKey(T key);
private:
    NodePointer<T, U> root;
};

template <typename T, typename U>
RedBlackTree<T, U>::RedBlackTree() {
    root = SimpleFactory<T, U>::makeSentinel();
}

template<typename T, typename U>
void RedBlackTree<T, U>::put(T key, U value) {
    //auto putter = NodePutter<T, U>(root, new RBFactory<T, U>());
    auto putter = RBPutter<T, U>(root);
    putter.put(key, value);
    root = putter.obtainRoot();
}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsKey(T key) {
    auto finder = KeyFinder<T, U>(root);
    finder.setDesiredKey(key);
    finder.find();
    return finder.nodeFound();
}

template<typename T, typename U>
bool RedBlackTree<T, U>::containsValue(U value) {
    return true;
}

template<typename T, typename U>
void RedBlackTree<T, U>::removeKey(T key) {
    auto remover = RBRemover<T, U>(root);
    remover.remove(key);
    root = remover.obtainRoot();
}

#endif //SDIZO_1_REDBLACKTREE_H
