#ifndef SDIZO_1_RBREMOVER_H
#define SDIZO_1_RBREMOVER_H

#include "red_black_tree_lib/node_util/KeyFinder.h"
#include "red_black_tree_lib/node_util/ConsequentFinder.h"
#include "red_black_tree_lib/node_util/ConsequentLiberator.h"
#include "red_black_tree_lib/node_util/NodeReplacer.h"

template <typename T, typename U>
class RBRemover
{
public:
    explicit RBRemover(NodePointer<T, U> root);
    void remove(T key);
    NodePointer<T, U> obtainRoot();

private:
    NodePointer<T, U> root;
};

template<typename T, typename U>
RBRemover<T, U>::RBRemover(NodePointer <T, U> root) {
    this->root = root;
}

template<typename T, typename U>
void RBRemover<T, U>::remove(T key) {
    auto finder = KeyFinder<T, U>(root);
    finder.setDesiredKey(key);
    finder.find();
    bool treeContainsThatKey = finder.nodeFound();
    if(treeContainsThatKey)
    {
        auto nodeToRemove = rbcast(finder.getFound());
        auto consequentFinder = ConsequentFinder<T, U>(nodeToRemove);
        auto consequent = rbcast(consequentFinder.find());
        auto consequentSide = consequentFinder.getConsequentSide();

        if(consequent->get(consequentSide)->isNil()){
            auto customSentinel = RBFactory<T, U>().createSentinel(consequent);
            consequent->setSide(customSentinel, consequentSide);
        }

        auto liberator = ConsequentLiberator<T, U>(consequent);
        liberator.free();
        root = liberator.obtainRoot();
        auto replacer = NodeReplacer<T, U>(nodeToRemove);
        replacer.replaceWithNode(consequent);
        root = replacer.obtainRoot();


        bool consequentWasBlack = false;
        if(consequent->isBlack())
            consequentWasBlack = true;

        if(nodeToRemove->isBlack())
            consequent->paintBlack();
        else
            consequent->paintRed();
    }
}

template<typename T, typename U>
NodePointer<T, U> RBRemover<T, U>::obtainRoot() {
    return root;
}

#endif //SDIZO_1_RBREMOVER_H
