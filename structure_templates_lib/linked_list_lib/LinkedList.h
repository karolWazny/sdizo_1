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
    void swap(int, int) noexcept (false);
    type remove(int);
    void pushBack(type);
    type get(int index);
    bool isEmpty();
    int getLength();
    LinkedList<type>();
    class Nexter : public  INextable<type> {
    public:
        std::shared_ptr<LinkedListItem<type>> pointer;
        Nexter();
        std::shared_ptr<LinkedListItem<type>> getNext() override;
        void setNext(std::shared_ptr<LinkedListItem<type>> next) override;
        bool hasNext() override;
    };
    std::string toString();
private:
    std::weak_ptr<LinkedListItem<type> > lastIndex;
    std::shared_ptr< Nexter > zeroIndex;
    int length;
    std::shared_ptr< LinkedListItem<type> > getItem(int index);
};

template<typename type>
std::shared_ptr< LinkedListItem<type> > LinkedList<type>::getItem(const int index)
{
    int counter = 0;
    auto buffer = zeroIndex->getNext();
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
        auto indexOne = zeroIndex->getNext();
        zeroIndex->setNext(std::make_shared<LinkedListItem<type>>(content, zeroIndex));
        zeroIndex->getNext()->setNext(indexOne);
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

    auto buffer = zeroIndex->getNext();
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
type LinkedList<type>::remove(int index)
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
        zeroIndex->setNext(std::shared_ptr<LinkedListItem<type>>(new LinkedListItem<type>(element, zeroIndex)));
        lastIndex = zeroIndex->getNext();
    }
    else {
        lastIndex.lock()->putAfter(element);
        lastIndex = lastIndex.lock()->getNext();
    }
    length++;
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
    zeroIndex = std::make_shared<Nexter>();
}

template<typename type>
LinkedList<type>::Nexter::Nexter()
{
    pointer = std::shared_ptr<LinkedListItem<type>>(nullptr);
}

template<typename type>
std::shared_ptr<LinkedListItem<type>> LinkedList<type>::Nexter::getNext()
{
    return pointer;
}

template<typename type>
void LinkedList<type>::Nexter::setNext(std::shared_ptr<LinkedListItem<type>> next)
{
    pointer = next;
}

template<typename type>
bool LinkedList<type>::Nexter::hasNext()
{
    return pointer != nullptr;
}

template<typename T>
std::string LinkedList<T>::toString()
{
    std::string output = "[";
    if(!isEmpty())
    {
        auto buffer = zeroIndex->getNext();
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

#endif //SDIZO_1_LINKEDLIST_H
