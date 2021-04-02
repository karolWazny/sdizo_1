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

        if(consequent->isNil())
        {
            auto customSentinel = RBFactory<T, U>().createSentinel(nodeToRemove);
            nodeToRemove->setSide(customSentinel, consequentSide);
            consequent = rbcast(customSentinel);
        }

        //v2
        //zapisujemy w doubleParent pozycję w drzewie zajmowaną przez ojca następnika
        auto doubleBlackParent = rbcast(consequent->getParent());
        if(doubleBlackParent == nodeToRemove)
            doubleBlackParent = consequent;
        //zabezpieczenie przypadku granicznego

        auto doubleBlackSide = Side::RIGHT;
        if(doubleBlackParent->getKey() > consequent->getKey())
            doubleBlackSide = Side::LEFT;

        //zapamiętujemy kolor następnika
        bool consequentWasBlack = consequent->isBlack();


        auto liberator = ConsequentLiberator<T, U>(root);
        liberator.free(consequent);
        root = liberator.obtainRoot();
        auto replacer = NodeReplacer<T, U>(nodeToRemove);
        replacer.replaceWithNode(consequent);//todo tu coś nie gra
        if(root == nodeToRemove)
            root = replacer.obtainRoot();

        //v2
        //przekolorowanie następnika na kolor węzła usuwanego
        if(nodeToRemove->isBlack())
            consequent->paintBlack();
        else
            consequent->paintRed();
        //v2
        //
        if(consequentWasBlack)
        {
            auto doubleBlack = rbcast(doubleBlackParent->get(doubleBlackSide));
            if(doubleBlack->isNil())
            {
                doubleBlack = rbcast(RBFactory<T, U>().createSentinel(doubleBlackParent));
                doubleBlackParent->setSide(doubleBlack, doubleBlackSide);
            }

            //kontrolujemy customową zaślepkę
            int count = 0;

            while(true)
            {
                if(doubleBlack->isRed() || (doubleBlackParent->isNil() && count > 0))
                {
                    doubleBlack->paintBlack();
                    return;
                }

                //przygotowanie genealogii do przesuwania czarności w górę
                auto doubleBlackSibling = rbcast(doubleBlackParent->get(!doubleBlackSide));

                //przypadek: brat x jest czerwony (sprowadzenie do któregoś z kolejnych przypadków)
                if(doubleBlackSibling->isRed())
                {
                    auto rotator = NodeRotator<T, U>();
                    rotator.rotate(doubleBlackParent, doubleBlackSide);
                    root = rotator.obtainRoot();
                    doubleBlackParent->paintRed();
                    doubleBlackSibling->paintBlack();
                    doubleBlackSibling = rbcast(doubleBlackParent->get(!doubleBlackSide));
                }
                //przypadek: brat x jest czarny i ma czarnych synów
                if(rbcast(doubleBlackSibling->getRight())->isBlack() && rbcast(doubleBlackSibling->getLeft())->isBlack())
                {
                    doubleBlackSibling->paintRed();
                    doubleBlack = doubleBlackParent;

                    //aktualizacja genealogii
                    doubleBlackParent = rbcast(doubleBlack->getParent());
                    doubleBlackSide = Side::RIGHT;
                    if(doubleBlackParent->getKey() > doubleBlack->getKey())
                        doubleBlackSide = Side::LEFT;
                    doubleBlackSibling = rbcast(doubleBlackParent->get(!doubleBlackSide));

                    continue;
                }
                //przypadek: brat x jest czarny i ma czerwonego syna z tej samej strony, czarnego z przeciwnej
                if(rbcast(doubleBlackSibling->get(!doubleBlackSide))->isBlack())
                {
                    auto rotator = NodeRotator<T, U>();
                    rotator.rotate(doubleBlackSibling, !doubleBlackSide);
                    doubleBlackSibling->paintRed();
                    rbcast(doubleBlackSibling->getParent())->paintBlack();

                    //aktualizacja genealogii
                    doubleBlackSibling = rbcast(doubleBlackParent->get(!doubleBlackSide));
                }
                //przypadek: brat x jest czarny i ma syna czerwonego syna z przeciwnej strony
                if(rbcast(doubleBlackSibling->get(!doubleBlackSide))->isRed())
                {
                    auto rotator = NodeRotator<T, U>();
                    rotator.rotate(doubleBlackParent, doubleBlackSide);
                    root = rotator.obtainRoot();
                    auto siblingWasBlack = doubleBlackSibling->isBlack();
                    if(doubleBlackParent->isRed())
                        doubleBlackSibling->paintRed();
                    else
                        doubleBlackSibling->paintBlack();

                    if(siblingWasBlack)
                        doubleBlackParent->paintBlack();
                    else
                        doubleBlackParent->paintRed();

                    rbcast(doubleBlackSibling->get(!doubleBlackSide))->paintBlack();

                    //doubleBlackParent->paintBlack();
                    //alternatywna próba:
                    doubleBlack = doubleBlackParent;
                    //iiii aktualizacja genealogii
                    doubleBlackParent = rbcast(doubleBlack->getParent());
                    doubleBlackSide = Side::RIGHT;
                    if(doubleBlackParent->getKey() > doubleBlack->getKey())
                        doubleBlackSide = Side::LEFT;
                    doubleBlackSibling = rbcast(doubleBlackParent->get(!doubleBlackSide));

                    //break;
                }
                count++;
            }
        }
    }
}

template<typename T, typename U>
NodePointer<T, U> RBRemover<T, U>::obtainRoot() {
    return root;
}

#endif //SDIZO_1_RBREMOVER_H
