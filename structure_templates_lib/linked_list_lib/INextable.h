//
// Created by admin on 02.03.2021.
//

#ifndef SDIZO_1_INEXTABLE_H
#define SDIZO_1_INEXTABLE_H

#include <memory>

template <typename T>
class LinkedListItem;

template <typename T>
class INextable
{
public:
    virtual std::shared_ptr<LinkedListItem<T>> getNext();
    virtual void setNext(std::shared_ptr<LinkedListItem<T>>);
    virtual bool hasNext();
};

template <typename T>
bool INextable<T>::hasNext() {
    return false;
}

template <typename T>
std::shared_ptr<LinkedListItem<T>> INextable<T>::getNext() {
    return std::shared_ptr<LinkedListItem<T>>(nullptr);
}

template <typename T>
void INextable<T>::setNext(std::shared_ptr<LinkedListItem<T>> pointer) {
    return;
}

#endif //SDIZO_1_INEXTABLE_H
