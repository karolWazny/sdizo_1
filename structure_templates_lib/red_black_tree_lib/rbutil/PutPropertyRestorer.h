#ifndef SDIZO_1_PUTPROPERTYRESTORER_H
#define SDIZO_1_PUTPROPERTYRESTORER_H

#include "red_black_tree_lib/node_util/NodeUtility.h"
#include "red_black_tree_lib/nodes/Node.h"
#include "red_black_tree_lib/node_util/NodeRotator.h"

template <typename T, typename U>
class PutPropertyRestorer : public NodeUtility<T, U>
{
public:
    void restoreFrom(RBNodePtr<T, U> freshNode);
private:
    void updateGenealogy();

    RBNodePtr<T, U> startingNode;
    RBNodePtr<T, U> parent;
    RBNodePtr<T, U> uncle;
    RBNodePtr<T, U> grand;
    RBNodePtr<T, U> root;
    Side parentSide;
    Side startingSide;
};

template<typename T, typename U>
void PutPropertyRestorer<T, U>::restoreFrom(RBNodePtr<T, U> freshNode) {
    startingNode = freshNode;
    updateGenealogy();
    while(parent->isRed()){
        //stryj jest czerwony
        if(uncle->isRed())
        {
            uncle->paintBlack();
            grand->paintRed();
            parent->paintBlack();
            startingNode = grand;
        } else {
            NodeRotator<T, U> rotator = NodeRotator<T, U>();
            if(startingSide != parentSide)
            {//todo w tym warunku jest coś skopane, uruchamia się dopiero w tym nowym teście
                startingNode = parent;
                rotator.rotate(startingNode, parentSide);
                root = rbcast(rotator.obtainRoot());
                updateGenealogy();//todo tutaj diabeł tkwi
            }
            parent->paintBlack();
            grand->paintRed();
            rotator.rotate(grand, !parentSide);
            root = rbcast(rotator.obtainRoot());
            break;
        }
        //jedziemy w górę
        updateGenealogy();
    }
}

template<typename T, typename U>
void PutPropertyRestorer<T, U>::updateGenealogy() {
    currentNode = startingNode;
    parent = rbcast(startingNode->getParent());
    grand = rbcast(parent->getParent());//todo i tu leży pies pogrzebany
    if(parent->getKey() < grand->getKey())
        parentSide = Side::LEFT;
    else
        parentSide = Side::RIGHT;
    if(startingNode->getKey() < parent->getKey())
        startingSide = Side::LEFT;
    else
        startingSide = Side::RIGHT;
    uncle = rbcast(grand->get(!parentSide));
}

#endif //SDIZO_1_PUTPROPERTYRESTORER_H
