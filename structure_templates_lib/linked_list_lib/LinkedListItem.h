//
// Created by admin on 02.03.2021.
//

#ifndef SDIZO_1_LINKEDLISTITEM_H
#define SDIZO_1_LINKEDLISTITEM_H

#include "INextable.h"

template <typename type>
class LinkedListItem : public INextable<type>
{
private:
    std::weak_ptr<INextable<type>> previous;
    type content;
    std::shared_ptr<INextable<type>> next;
    void putAfter(INextable<type>);
public:
    LinkedListItem(type);
    LinkedListItem(type, std::shared_ptr<INextable<type>>);
    type getContent() override;
    std::shared_ptr<INextable<type>> getNext() override;
    void setNext(std::shared_ptr<INextable<type>> next) override;
    std::shared_ptr<INextable<type>> getPrevious() override;
    void putAfter(type) override;
    void remove() override;
    void swap(std::shared_ptr<INextable<type>>) override;
    bool hasNext() override;
};

template <typename T>
bool LinkedListItem<T>::hasNext()
{
    return next != nullptr;
}

template <typename T>
void LinkedListItem<T>::setNext(std::shared_ptr<INextable<T>> next) {
    this->next = next;
}

template <typename T>
std::shared_ptr<INextable<T>> LinkedListItem<T>::getNext() {
    return next;
}

template<typename type>
void LinkedListItem<type>::swap(std::shared_ptr<INextable<type>>replacement) {
    auto elem_0 = replacement->getPrevious();
    auto elem_2 = replacement->getNext();
    auto buffer_1 = elem_0->getNext();
    elem_0->setNext(this->previous.lock()->getNext());
    this->previous.lock()->setNext(buffer_1);
    buffer_1 = replacement->getNext();
    replacement->setNext(this->next);
    this->next = buffer_1;
    auto buffer_2 = this->next->getPrevious();
    this->next->setPrevious(elem_2->getPrevious());
    elem_2->setPrevious(buffer_2);
    buffer_2 = replacement->getPrevious();
    replacement->setPrevious(this->previous);
    this->previous = buffer_2;
}

template<typename type>
type LinkedListItem<type>::getContent() {
    return content;
}

template<typename type>
LinkedListItem<type>::LinkedListItem(type content)
{
    this->content = content;
    next = std::shared_ptr<LinkedListItem<type>>(nullptr);
    previous = std::shared_ptr<INextable<type>>(nullptr);
}

template<typename type>
LinkedListItem<type>::LinkedListItem(type content, std::shared_ptr<INextable<type>> pointer)
{
    this->content = content;
    next = std::shared_ptr<LinkedListItem<type>>(nullptr);
    previous = pointer;
}

template<typename type>
void LinkedListItem<type>::putAfter(type nextItem)
{
    auto buffer = std::make_shared<LinkedListItem<type>>(nextItem);
    if (next != nullptr) {
        buffer->next = next;
        next->setPrevious(buffer);
    }
    buffer->previous = previous.lock()->getNext();
    next = buffer;
}

template<typename type>
void LinkedListItem<type>::remove()
{
    if(next != nullptr)
    {
        next->setPrevious(previous);
    }
    previous.lock()->setNext(next);
}

template<typename type>
void LinkedListItem<type>::putAfter(INextable<type> nextItem)
{
    auto buffer = next;
    next = std::shared_ptr<LinkedListItem<type>>(nextItem);
    buffer->previous = next;
    next->next = buffer;
    next->previous = std::weak_ptr<LinkedListItem<type>>(this);
}

template<typename type>
std::shared_ptr<INextable<type>> LinkedListItem<type>::getPrevious()
{
    return previous.lock();
}


#endif //SDIZO_1_LINKEDLISTITEM_H
