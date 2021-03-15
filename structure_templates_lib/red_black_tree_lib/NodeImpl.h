//
// Created by admin on 13.03.2021.
//

#ifndef SDIZO_1_NODEIMPL_H
#define SDIZO_1_NODEIMPL_H

template <typename T>
class NodeImpl : public RedBlackNode<T>
{
public:
    NodeImpl(NodePointer<T> parent, T key);
    virtual ~NodeImpl();
    void setParent(NodePointer<T> parent) override;
    void insertAfter(NodePointer<T> newNode) override;
    bool subtreeContains(T key) override;
    T getKey() override;
    bool hasLeftChild() override;
    bool hasRightChild() override;
    NodePointer<T> getParent();
private:
    NodePointer<T> getRightChild() override;
    NodePointer<T> getLeftChild() override;
    void setRightChild(NodePointer<T> rightChild) override;
    void setLeftChild(NodePointer<T> leftChild) override;


    void insertLeftwards(NodePointer<T> newNode);
    void insertRightwards(NodePointer<T> newNode);
    void insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child);
    bool leftSubtreeContains(T key);
    bool rightSubtreeContains(T key);
    bool subtreeOnTheSideOfContains(T key, NodePointer<T>& child);
    NodePointer<T> getSibling();
    bool isRightChild();

    static NodePointer<T> NIL;
    NodePointer<T> leftChild;
    NodePointer<T> rightChild;
    NodeWeakPtr<T> parent;
    T key;
};

template <typename T>
NodePointer<T> NodeImpl<T>::NIL = NodePointer<T>(new RedBlackNil<T>(nullptr));

template<typename T>
void NodeImpl<T>::setParent(NodePointer<T> parent) {
    this->parent = parent;
}

template<typename T>
void NodeImpl<T>::insertAfter(NodePointer<T> newNode) {
    if(newNode->getKey() < this->key)
    {
        insertLeftwards(newNode);
        return;
    }
    insertRightwards(newNode);
    return;
}

template<typename T>
bool NodeImpl<T>::subtreeContains(T key) {
    if(this->key == key)
    {
        return true;
    }
    if(this->key > key)
    {
        return leftSubtreeContains(key);
    }
    return rightSubtreeContains(key);
}

template<typename T>
T NodeImpl<T>::getKey()
{
    return key;
}

template<typename T>
NodePointer<T> NodeImpl<T>::getRightChild()
{
    return rightChild;
}

template<typename T>
NodePointer<T> NodeImpl<T>::getLeftChild()
{
    return leftChild;
}

template<typename T>
void NodeImpl<T>::setRightChild(NodePointer<T> rightChild)
{
    if(!rightChild)
        setRightChild(NIL);
    else
        this->rightChild = rightChild;
}

template<typename T>
void NodeImpl<T>::setLeftChild(NodePointer<T> leftChild)
{
    if(!leftChild)
        setLeftChild(NIL);
    else
        this->leftChild = leftChild;
}

template<typename T>
NodeImpl<T>::NodeImpl(NodePointer<T> parent, T key) {
    this->key= key;
    this->parent = parent;
    leftChild = NIL;
    rightChild = NIL;
}


template<typename T>
void NodeImpl<T>::insertLeftwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, leftChild);
}

template<typename T>
void NodeImpl<T>::insertRightwards(NodePointer<T> newNode) {
    insertOnTheSideOf(newNode, rightChild);
}

template<typename T>
void NodeImpl<T>::insertOnTheSideOf(NodePointer<T> newNode, NodePointer<T> & child) {
    if(child == NIL)
    {
        child = newNode;
        return;
    }
    newNode->setParent(child);
    child->insertAfter(newNode);
}

template<typename T>
bool NodeImpl<T>::leftSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, leftChild);
}

template<typename T>
bool NodeImpl<T>::rightSubtreeContains(T key) {
    return subtreeOnTheSideOfContains(key, rightChild);
}

template<typename T>
bool NodeImpl<T>::subtreeOnTheSideOfContains(T key, NodePointer<T>& child) {
    return child->subtreeContains(key);
}


template<typename T>
NodePointer<T> NodeImpl<T>::getParent() {
    return parent;
}

template<typename T>
NodePointer<T> NodeImpl<T>::getSibling() {
    if(!isChild())
    {
        return NIL;
    }
    auto parentKey = getParent()->getKey();
    if(parentKey > this->key)
    {
        return getParent()->getRightChild();
    }
    return getParent()->getLeftChild();
}

template<typename T>
bool NodeImpl<T>::isRightChild()
{
    if(!isChild())
    {
        return false;
    }
    auto parentKey = getParent()->getKey();
    return (this->key >= parentKey);
}

template<typename T>
NodeImpl<T>::~NodeImpl() {
    if(leftChild != NIL)
    {
        delete leftChild;
    }
    if(rightChild != NIL)
    {
        delete rightChild;
    }
    std::cout << "Deleteing node with key: " + this->getKey();
}

template<typename T>
bool NodeImpl<T>::hasLeftChild() {
    return leftChild != NIL;
}

template<typename T>
bool NodeImpl<T>::hasRightChild() {
    return rightChild != NIL;
}

#endif //SDIZO_1_NODEIMPL_H
