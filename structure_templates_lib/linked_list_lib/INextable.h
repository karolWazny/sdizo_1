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
    virtual std::shared_ptr<INextable<T>> getNext();
    virtual void setNext(std::shared_ptr<INextable<T>>);
    virtual bool hasNext();
    virtual T getContent();
    virtual std::shared_ptr<INextable<T>> getPrevious();
    virtual void setPrevious(std::weak_ptr<INextable<T>>);
    virtual void putAfter(T);
    virtual void remove();
    virtual void swap(std::shared_ptr<INextable<T>>);
};

template <typename T>
bool INextable<T>::hasNext() {
    return false;
}

template <typename T>
std::shared_ptr<INextable<T>> INextable<T>::getNext() {
    return std::shared_ptr<LinkedListItem<T>>(nullptr);
}

template <typename T>
void INextable<T>::setNext(std::shared_ptr<INextable<T>> pointer) {
    return;
}

template<typename T>
T INextable<T>::getContent() {
    return NULL;
}

template<typename T>
std::shared_ptr<INextable<T>> INextable<T>::getPrevious() {
    return std::shared_ptr<INextable<T>>();
}

template<typename T>
void INextable<T>::putAfter(T) {

}

template<typename T>
void INextable<T>::remove() {

}

template<typename T>
void INextable<T>::swap(std::shared_ptr<INextable<T>>) {

}

template<typename T>
void INextable<T>::setPrevious(std::weak_ptr<INextable<T>>) {

}

#endif //SDIZO_1_INEXTABLE_H
