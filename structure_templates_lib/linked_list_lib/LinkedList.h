//
// Created by admin on 02.03.2021.
//

#ifndef SDIZO_1_LINKEDLIST_H
#define SDIZO_1_LINKEDLIST_H

#include "LinkedListItem.h"
#include <string>

template <typename type>
class LinkedList
{
public:
    void addAtPosition(type, int);
    void putAfter(type whereToPut, type elementToAdd);
    void swap(int, int) noexcept (false);
    type removeAt(int index);
    bool remove(type element);
    void pushBack(type);
    void pushFront(type);
    type removeLast();
    type removeFirst();
    type get(int index);
    bool isEmpty();
    int getLength();
    LinkedList<type>();
    class Nexter : public  INextable<type> {
    public:
        std::shared_ptr<INextable<type>> pointer;
        std::weak_ptr<INextable<type>> mThis;
        Nexter();
        void setMThis(std::shared_ptr<INextable<type>> mThis);
        std::shared_ptr<INextable<type>> getNext() override;
        void setNext(std::shared_ptr<INextable<type>> next) override;
        void putAfter(type element) override;
        bool hasNext() override;
    };
    std::string toString();
private:
    std::weak_ptr<INextable<type>> lastIndex;
    std::shared_ptr< Nexter > guard;
    int length;
    std::shared_ptr< INextable<type> > getItem(int index);
};

template<typename type>
std::shared_ptr< INextable<type> > LinkedList<type>::getItem(const int index)
{
    int counter = 0;
    auto buffer = guard->getNext();
    while (counter < index) {
        buffer = buffer->getNext();
        counter++;
    }
    return buffer;
}

template<typename type>
void LinkedList<type>::addAtPosition(type content, int index)
{
    if (!index) {
        pushFront(content);
        return;
    }
    else {
        auto buffer = getItem(index - 1);
        buffer->putAfter(content);
        length++;
    }
}

template<typename type>
void LinkedList<type>::swap(int index1, int index2) noexcept(false)
{
    if (index1 == index2) {
        return;
    }
    if (index1 > index2) {
        auto buffer = index1;
        index1 = index2;
        index2 = buffer;
    }

    auto buffer = guard->getNext();
    int count = 0;
    while (count < index1) {
        buffer = buffer->getNext();
        count++;
    }
    auto item_1 = buffer;
    while (count < index2) {
        buffer = buffer->getNext();
        count++;
    }
    auto item_2 = buffer;
    item_1->swap(item_2);
}

template<typename type>
type LinkedList<type>::removeAt(int index)
{
    auto buffer = getItem(index);
    auto out = buffer->getContent();
    buffer->remove();
    length--;
    return out;
}

template<typename type>
void LinkedList<type>::pushBack(type element)
{
    if (!length) {
        guard->setNext(std::shared_ptr<LinkedListItem<type>>(new LinkedListItem<type>(element, guard)));
        lastIndex = guard->getNext();
    }
    else {
        lastIndex.lock()->putAfter(element);
        lastIndex = lastIndex.lock()->getNext();
    }
    length++;
}

template <typename T>
void LinkedList<T>::pushFront(T element)
{
    if(!isEmpty())
    {
        guard->putAfter(element);
    } else
    {
        guard->putAfter(element);
        lastIndex = guard->getNext();
    }
    length++;
}

template <typename T>
T LinkedList<T>::removeFirst()
{
    return removeAt(0);
}

template <typename T>
T LinkedList<T>::removeLast()
{
    auto buffer = lastIndex.lock();
    lastIndex = buffer->getPrevious();
    buffer->remove();
    length--;
    return buffer->getContent();
}

template<typename type>
type LinkedList<type>::get(int index) {
    return getItem(index)->getContent();
}

template<typename type>
bool LinkedList<type>::isEmpty()
{
    return !length;
}

template<typename type>
int LinkedList<type>::getLength()
{
    return length;
}

template<typename type>
LinkedList<type>::LinkedList()
{
    length = 0;
    guard = std::make_unique<Nexter>();
    guard->setMThis(guard);
}

template<typename type>
LinkedList<type>::Nexter::Nexter()
{
    pointer = std::shared_ptr<LinkedListItem<type>>(nullptr);
}

template<typename type>
std::shared_ptr<INextable<type>> LinkedList<type>::Nexter::getNext()
{
    return pointer;
}

template<typename type>
void LinkedList<type>::Nexter::setNext(std::shared_ptr<INextable<type>> next)
{
    pointer = next;
}

template<typename type>
bool LinkedList<type>::Nexter::hasNext()
{
    return pointer != nullptr;
}

template<typename type>
void LinkedList<type>::Nexter::putAfter(type element) {
    auto buffer = std::make_shared<LinkedListItem<type>>(element);
    if (pointer != nullptr) {
        buffer->setNext(pointer);
        pointer->setPrevious(buffer);
    }
    buffer->setPrevious(mThis);
    pointer = buffer;
}

template<typename type>
void LinkedList<type>::Nexter::setMThis(std::shared_ptr<INextable<type>> mThis) {
    this->mThis = mThis;
}

template<typename T>
std::string LinkedList<T>::toString()
{
    std::string output = "[";
    if(!isEmpty())
    {
        auto buffer = guard->getNext();
        output += std::to_string(buffer->getContent());
        while(buffer->hasNext())
        {
            output += ", ";
            buffer = buffer->getNext();
            output += std::to_string(buffer->getContent());
        }
    }
    return output + "]";
}

template<typename type>
bool LinkedList<type>::remove(type element)
{
    if(isEmpty())
    {
        return false;
    }
    auto buffer = guard->getNext();
    for(int i = 0; i < length; i++)
    {
        if(buffer->getContent() == element)
        {
            if(i == --length)
            {
                lastIndex = buffer->getPrevious();
            }
            buffer->remove();
            return true;
        }
        buffer = buffer->getNext();
    }
    return false;
}

template<typename type>
void LinkedList<type>::putAfter(type whereToPut, type elementToAdd)
{
    auto buffer = guard->getNext();
    for(int i = 0; i < length; i++)
    {
        if(buffer->getContent() == whereToPut)
        {
            buffer->putAfter(elementToAdd);
            if(i == length - 1)
            {
                lastIndex = buffer->getNext();
            }
            return;
        }
        buffer = buffer->getNext();
    }
    pushFront(elementToAdd);
}

#endif //SDIZO_1_LINKEDLIST_H