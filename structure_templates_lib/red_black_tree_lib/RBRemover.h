#ifndef SDIZO_1_RBREMOVER_H
#define SDIZO_1_RBREMOVER_H

#include <red_black_tree_lib/node_util/NodeRotator.h>
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



        //added
        if(consequent->get(consequentSide)->isNil()){
            auto customSentinel = RBFactory<T, U>().createSentinel(consequent);
            consequent->setSide(customSentinel, consequentSide);
        }
        auto nodeX = rbcast(consequent->getParent());

        bool consequentWasBlack = false;
        if(consequent->isBlack())
            consequentWasBlack = true;
        //end added



        auto liberator = ConsequentLiberator<T, U>(consequent);
        liberator.free();
        root = liberator.obtainRoot();
        auto replacer = NodeReplacer<T, U>(nodeToRemove);
        replacer.replaceWithNode(consequent);
        root = replacer.obtainRoot();

        //added
        if(nodeX == nodeToRemove)
            nodeX = consequent;

        if(nodeToRemove->isBlack())
            consequent->paintBlack();
        else
            consequent->paintRed();

        auto xParent = rbcast(consequent->getParent());
        Side xSide = Side::RIGHT;
        if(xParent->getKey() > nodeX->getKey())
            xSide = Side::LEFT;
        auto nodeW = rbcast(xParent->get(!xSide));

        while(!xParent->isNil() && nodeX->isBlack()){
            if(nodeW->isRed()){
                nodeW->paintBlack();
                xParent->paintRed();
                auto rotator = NodeRotator<T, U>();
                rotator.rotate(xParent, xSide);
                root = rotator.obtainRoot();
                nodeW = rbcast(xParent->get(!consequentSide));
            }
            if(rbcast(nodeW->getLeft())->isBlack() && rbcast(nodeW->getRight())->isBlack()){
                nodeW->paintRed();
                nodeX = xParent;
            } else {//tu nie jestem pewien zagnieżdżenia
                if(rbcast(nodeW->get(!xSide))->isBlack()){
                    rbcast(nodeW->get(xSide))->paintBlack();
                    nodeW->paintRed();
                    auto rotator = NodeRotator<T, U>();
                    rotator.rotate(nodeW, !xSide);
                    root = rotator.obtainRoot();
                    nodeW = rbcast(xParent->get(!xSide));
                }
            }
            if(xParent->isBlack())
                nodeW->paintBlack();
            else
                nodeW->paintRed();
            xParent->paintBlack();
            rbcast(nodeW->get(!xSide))->paintBlack();
            auto rotator = NodeRotator<T, U>();
            rotator.rotate(xParent, xSide);
            root = rotator.obtainRoot();
            nodeX = rbcast(root);


            xParent = rbcast(consequent->getParent());
            Side xSide = Side::RIGHT;
            if(xParent->getKey() > nodeX->getKey())
                xSide = Side::LEFT;
            nodeW = rbcast(xParent->get(!xSide));
        }
        nodeX->paintBlack();
        //end added
    }
}

template<typename T, typename U>
NodePointer<T, U> RBRemover<T, U>::obtainRoot() {
    return root;
}

#endif //SDIZO_1_RBREMOVER_H
